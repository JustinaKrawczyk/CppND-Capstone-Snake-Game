#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
#include "results.h"

/**template <typename T>
T MessageQueue<T>::receive()
{
    std::unique_lock<std::mutex> ulock(msg_queue_mtx);
    msg_queue_cond.wait(ulock, [this]{return !queue.empty();});

    T msg = std::move(queue.back());
    queue.pop_back();

    return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> lockguard(msg_queue_mtx);
    queue.push_back(std::move(msg));

    msg_queue_cond.notify_one();
}**/


Results::Results(){
  std::shared_ptr<std::vector<Player>> resultsTable = std::make_shared<std::vector<Player>>();
  resultsTable = nullptr;
  std::shared_ptr<Player> currentPlayer = std::make_shared<Player>();
  currentPlayer = nullptr;
}

Results::~Results(){}

std::string Results::getResultsDB() const{
  return resultsDB;
}

std::shared_ptr<Player> Results::getCurrentPlayer(){
  return currentPlayer;
}

void Results::waitforPlayerName(std::promise<Results> &&prms, std::string playerName){
    
  while(true){
    std::cout << "Welcome to the Snake Game!\n";
    std::cout << "Please type in your name: ";
    
    std::getline(std::cin, playerName);
    if(!playerName.empty()){
      currentPlayer->setName(playerName);
      prms.setValue(playerName);
      return;
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void Results::writeAllResults(){
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  
  std::ofstream dbfile;
  dbfile.open(resultsDB);
  if(dbfile){
    dbfile << "Name" << "\t" << "Score" << "Size" << "\n";
    //std::lock_guard<std::mutex> lock_guard(mtx);
    std::unique_lock<std::mutex> lk(mtx);
    conditionVariable.wait(lk, []{return ready;});
    for(auto &result : *resultsTable){
      dbfile << result->getName() << "\t" << result->getScore() << result->getSnakeSize() << "\n";
    }
    resultsWritten = true; // is this used?
    processed = true;
    
  }else{
      cout << "Cannot open db file. Maybe it does not exist.\n";
  }
  dbfile.close();
  lk.unlock();
  conditionVariable.notify_one();
}

/**void Results::writeResults(Player &player){
  std::ofstream dbfile;
  dbfile.open(resultsDB);
  if(dbfile){
    // write player results into file
    dbfile << "Name" << "\t" << "Score" << "Size" << "\n";
    dbfile << player.getName() << "\t" << player.getScore() << player.getSnakeSize() << "\n";
  }
  
  dbfile.close();
}*/

/** Reads overall game results from the DB which is represented by the dbfile */
void Results::readResults(){
  std::ifstream dbfile;
  dbfile.open(resultsDB);
  
  if(dbfile){
    std::string line;
    std::vector<std::string> tokens;

    // throw header line in file away
    std::getline(dbfile, line);
    while(std::getline(dbfile,line)){
      Player player;
      
      std::istringstream sline(line);
      std::string token;
      while(std::getline(sline, token, '\t')){
        tokens.push_back(token);
      }

      player.setName(tokens[0]);
      player.setScore(stoi(tokens[1]));
      player.setSnakeSize(stoi(tokens[2]));
      
      resultsTable->push_back(&player); // how to push player into vector as a reference or a pointer?
    }
    
    dbfile.close();
  }
}

void Results::calculateRanking(){
  // display results on screen or on console with ranking?
  // sort by score
  std::sort(resultsTable->begin(), resultsTable->end());
}
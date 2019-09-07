#include <iostream>
#include <fstream>
#include <sstream>
#include "results.h"

Results::Results(){}
Results::~Results(){}

std::string Results::getResultsDB() const{
  return resultsDB;
}

void Results::writeResults(Player &player){
  std::ofstream dbfile;
  dbfile.open(resultsDB);
  if(dbfile){
    // write player results into file
    dbfile << player.getName() << "\t" << player.getScore() << player.getSnakeSize() << "\n";
  }
  
  dbfile.close();
}

/** Reads overall game results from the DB which is represented by the dbfile */
void Results::readResults(){
  std::ifstream dbfile;
  dbfile.open(resultsDB);
  
  if(dbfile){
    std::string line;
    std::vector<std::string> tokens;
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
      
      resultTable.push_back(player); // how to push player into vector as a reference or a pointer?
    }
    
    dbfile.close();
  }
}

void Results::displayResults(){
  
}
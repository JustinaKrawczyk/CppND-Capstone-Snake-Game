#ifndef RESULTS_H
#define RESULTS_H

#include <string>
#include <vector>
#include <mutex>
#include <deque>
#include <queue>
#include <algorithm>
#include <condition_variable>

#include "player.h"

/**template <class T>
class MessageQueue {
  public:
    T receive();
    void send(T &&msg);
  
  private:
    std::deque<T> queue;
    std::condition_variable msg_queue_cond;
    std::mutex msg_queue_mtx;   
};*/

class Results{
  public:
   Results();
   ~Results();
  
   std::string getResultsDB() const;
   std::shared_ptr<Player> getCurrentPlayer();
   void waitforPlayerName(std::promise &&prms, std::string playerName);
   void writeAllResults();
   //void writeResults(Player &player);
   void readResults();
   void calculateRanking();
   std::shared_ptr<std::vector<Player*>> getResultsTable(); // maybe not as a vector of pointers?
  
   bool resultsWritten = false;
  
  private:
   std::string resultsDB = "results.txt";
   std::shared_ptr<std::vector<Player*>> resultsTable;
   std::shared_ptr<Player> currentPlayer;
  
   //std::mutex mtx;
   //std::condition_variable conditionVar;
   
  //std::shared_ptr<MessageQueue<std::string>> msgqueue;
};
#endif
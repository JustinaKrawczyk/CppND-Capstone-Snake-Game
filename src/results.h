#ifndef RESULTS_H
#define RESULTS_H

#include <string>
#include <vector>
#include "player.h"

class Results{
  public:
   Results();
   ~Results();
  
   std::string getResultsDB() const;
   void writeResults(Player &player);
   void readResults();
   void displayResults();
   std::vector<Player> getResultTable();
  
  private:
   std::string resultsDB = "results.txt";
   std::vector<Player> resultTable;
};
#endif
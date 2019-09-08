#include <iostream>
#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "player.h"
#include "results.h"

std::mutex mtx;
std::condition_variable conditionVariable;
bool ready = false;
bool processed = false;

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
   
  // Get input from console
  Results results;
  std::string playerName;
  
  // create promise/ future to get information if the player name is typed in
  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();
  std::thread t (Results::waitforPlayerName, std::move(prms), playerName);
  
  auto status = ftr.wait_for(std::chrono::milliseconds(4000));
  if(status == std::future::status::ready){
    cout << "Welcome to the Snake game " << ftr.get() << "!\n";
  }else if (status == std::future_status::timeout || status == std::future_status::deferred){
    cout << "Starting game without a player name.\n";
  }
    
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);

   // Update game result list
    std::lock_guard<std::mutex> lk(m);
    results->getCurrentPlayer()->setScore(game.GetScore());
    results->getCurrentPlayer()->setSnakeSize(game.GetSize());
    results->getResultsTable()->push_back(currentPlayer);
    ready = true;
    conditionVariable.notify_one();
    
    std::thread tr (Results::writeAllResults, &results); // todo maybe has to be placed over updata game result list
    std::unique_lock<std::mutex> lk(mtx);
    conditionVariable.wait(lk, []{return processed;});
    
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
  
    t.join();
    tr.join();
    
  return 0;
}
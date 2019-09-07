#include <iostream>
#include <string>
#include <thread>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "player.h"
#include "results.h"


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
  Player player;
  std::string playerName;
  //std::cout << "Please type in your name:";
  //std::getline(std::cin, playerName);
  player.setName("Doro");
  
  //std::this_thread::sleep_for(std::chrono::milliseconds(10));
  
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  
  // Update game result list
  player.setScore(game.GetScore());
  player.setSnakeSize(game.GetSize());
  
  Results results;
  results.writeResults(player);
  
  return 0;
}
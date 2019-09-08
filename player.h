#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
  public:
    Player();
    Player(std::string name, int score, int size) : name(name), score(score), snakeSize(size){};
   ~Player();
  
    // getter and setter
    void setName(std::string const name);
    void setScore(int const score);
    void setSnakeSize(int const size);
    std::string getName() const;
    int getScore() const;
    int getSnakeSize() const;
  
    bool operator<(const Player &a, const Player &b){
      return a.getScore() < b.getScore();
    }
  
  private:
    std::string name;
    int score;
    int snakeSize;
};

#endif
#include <string>
#include "player.h"

Player::Player(){}
Player::~Player(){}

void Player::setName(std::string const name){
 Player::name = name;
}

std::string Player::getName() const{
 return name;
}

void Player::setScore(int const score){
 Player::score = score;
}

int Player::getScore() const{
 return score;
}

void Player::setSnakeSize(int const size){
  Player::snakeSize = size;
}

int Player::getSnakeSize() const{
  return snakeSize;
}

#include "user.h"
#include <string>

User::User(){}

User::~User(){}

void User::setName(string const name){
 User::name = name;
}

void User::setScore(int const score){
 User::score = score;
}

string User::getName(){
 return name;
}

int User::getScore(){
 return score;
}


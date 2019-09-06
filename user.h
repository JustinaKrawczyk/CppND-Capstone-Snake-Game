#ifndef USER_H
#define USER_H

#include <string>

class User{
  public:
    User();
   ~User();
  
    // getter and setter
    void setName(string const name);
    void setScore(int const score);
    string getName();
    int getScore();
    // TODO getter and setter for timestamp - last played
  
  private:
    string name;
    int score;
    // timestamp - last played
};

#endif
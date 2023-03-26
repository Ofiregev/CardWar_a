#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include "player.hpp"
using namespace std;
namespace ariel
{
  class Game
  {
    private:
    Player p1;
    Player p2;
  public:
    string name;
    Game(Player p1, Player p2); // Constructor
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

  };
}

#endif

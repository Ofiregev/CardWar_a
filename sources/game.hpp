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
    string last_turn = "starting game";
    Player winner;
  public:
    Game(Player p1, Player p2); // Constructor
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void war();
    string getLastTurn();
    void setLastTurn(string last_turn);
    Player getWinner();
    void setWinner(Player name);

  };
}

#endif

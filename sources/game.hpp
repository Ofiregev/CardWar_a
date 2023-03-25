#ifndef GAME_HPP
#define GAME_HPP
using namespace std;
namespace ariel{
class Game {
  public:
    string name;
    Game(Player p1, Player p2);  // Constructor
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner(); 
    void printLog();
    void printStats();
};
}

#endif

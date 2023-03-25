
#ifndef PLAYER_HPP
#define PLAYER_HPP
using namespace std;
namespace ariel{
class Player {
  public:
    string name;
    Player(string name);  // Constructor
    int stacksize();
    int cardesTaken();
};
}

#endif

#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{

    Player::Player() {}

    Player::Player(string name)
    {
        this->name = name;
    }
    void Player::setStackSize(int size){}
    int Player::stacksize()
    {
        return -1;
    }
    int Player::cardesTaken()
    {
        return -1;
    }
    string Player::get_name(){
        return "-1";
    }

};

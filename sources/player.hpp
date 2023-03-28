
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;
namespace ariel {
    class Player {
        private:
            string name;
            Stack personal_stack;
            int cards_taken;
        public:
            Player();

            Player(string name); // Constructor
            void setStackSize(int size);
            string get_name();
            int stacksize();
            int cardesTaken();
    };
}

#endif


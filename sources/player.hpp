
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>

using namespace std;
namespace ariel {
    class Player {
        private:
            string name;
        public:
            Player();

            Player(string name); // Constructor
            int stacksize();
            int cardesTaken();
            string get_name();
            int get_stack_size();
            int get_cards_taken();
            void add_card();
            void add_cards(int num_cards);
            void clear_cards();
    };
}

#endif


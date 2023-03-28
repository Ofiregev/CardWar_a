#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;
namespace ariel {
    

    class Stack {
        private:
            Card top_card;
            int size;
        public:
            Stack();
            Stack(int size_of_stack);
            Card getTopCard();
            int getSize();

  };
}

#endif
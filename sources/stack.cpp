#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

namespace ariel
{
    Stack::Stack() {
        this->size = 26;
    }
    Stack::Stack(int size){}
    Card Stack::getTopCard()
    {
        return this->top_card;
    }
    int Stack::getSize()
    {
        return this->size;
    }
    void Stack::takeAcard()
    {
        this->size = this->size-1;
    }
    void Stack::setTopCard(Card card) {
        this->top_card = card;
    }
    void Stack::setStackSize(int size){
        if(size < 0){
            throw ("exeption");
        }
        this->size = size;
    }



}

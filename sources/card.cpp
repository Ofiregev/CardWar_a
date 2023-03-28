#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;

namespace ariel
{
    Card::Card(){}
    Card::Card(Sign sign, Number num, Color color){
        this->sign=sign;
        this->number=num;
        this->color=color;
    }
    Card Card::getCard()
    {
        return Card();
    }
    Number Card::getNumber()
    {
        return this->number;
    }
    string Card::toString(){
        return "card";
    }


}

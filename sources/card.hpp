#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
#include <string>
using namespace std;



namespace ariel {
    enum Sign {
        Heart,
        Diamond,
        Club,
        Spade
    };

    enum Number {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    enum Color {
        Red,
        Black
    };

    class Card {
        private:
            Sign sign;
            Number number;
            Color color;

        public:
            Number getNumber();
            Card getCard();

  };
}

#endif
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "namespace.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.getPoints() == 0);
    CHECK(p2.getPoints() == 0);
    


}
TEST_CASE("Test 2 - Check stacksize during game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playTurn();
    CHECK(p1.stacksize() == 25);
    CHECK(p2.stacksize() == 25);
    p1.getPersonalStack().setStackSize(-1);
    p1.setCardsTaken(57);
    CHECK_THROWS(p1.stacksize());
    CHECK_THROWS(p1.cardesTaken());
    

}
TEST_CASE("Test 3 - Check tie (war) between p1 and p2")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    Card p1_card = Card(Heart, Two, Black);
    Card p2_card = Card(Heart, Two, Red);
    p1.getPersonalStack().setTopCard(p1_card);
    p2.getPersonalStack().setTopCard(p2_card);
    
    game.playTurn();
    CHECK(p1.stacksize() <= 23);
    CHECK(p2.stacksize() <= 23);
    Card card = Card(Heart, Two, Black);
    p1.getPersonalStack().setTopCard(card);

    CHECK(p1.liftCard().getCard().getNumber() == card.getNumber());



    

    // Redirect the output stream to a stringstream
    // create 2 cards with equal value
    // add each card two every player stack- on top
    // playTurn()- tie occures.
    // palyer who won, now has at least 6 cards aside- 2 tie, 2 upsidedwon, 2 open
    // both players have at least 3 less in hand
}

// // during war, one player runs out of cards
// // during war, both players run out of cards
// // valid value and sign of cards


TEST_CASE("Check war between 2 players"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    Card p1_card = Card(Heart, Two, Black);
    Card p2_card = Card(Heart, Three, Black);
    p1.getPersonalStack().setTopCard(p1_card);
    p2.getPersonalStack().setTopCard(p2_card);
    game.playTurn();
    string last_turn = game.getLastTurn();
    stringstream turn;
    streambuf *lastTurnPrinted = cout.rdbuf();
    cout.rdbuf(turn.rdbuf());
    game.printLastTurn();
    cout.rdbuf(lastTurnPrinted); // store the message printed from printWiner
    CHECK(turn.str() == last_turn);
    CHECK(p2.cardesTaken() == 2);
    CHECK(p2.stacksize() == 25);
    CHECK(p1.stacksize() == 25);
}
TEST_CASE("Game stopped when one player wins")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playAll();
    string winnerName = game.getWinner().get_name();
    stringstream actuallWinner;
    streambuf *winnerPrinted = cout.rdbuf();
    cout.rdbuf(actuallWinner.rdbuf());
    game.printWiner();
    cout.rdbuf(winnerPrinted); // store the message printed from printWiner
    CHECK(actuallWinner.str() == winnerName);
    CHECK(game.getWinner().stacksize() == 0);
    CHECK(game.getWinner().cardesTaken() <=52);


}

TEST_CASE("Test 4 - Check stacksize during game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    Game game2(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize() == 25);


}
TEST_CASE("Test 4 - Check stacksize during game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    p1.setCardsTaken(20);
    p1.setDrawsNumber(3);
    p1.setPoints(7);
    p2.setCardsTaken(24);
    p2.setDrawsNumber(3);
    p2.setPoints(13);
    string status = p1.getStatus() + p2.getStatus();
    stringstream stat;
    streambuf *statPrinted = cout.rdbuf();
    cout.rdbuf(stat.rdbuf());
    game.printStats();
    cout.rdbuf(statPrinted); // store the message printed from printWiner
    CHECK(stat.str() == status);

    

}

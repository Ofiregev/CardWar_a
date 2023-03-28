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
    CHECK_THROWS(p1.getPersonalStack().setStackSize(-1));
    CHECK_THROWS(p1.setCardsTaken(57));
}
TEST_CASE("Test 2 - Check stacksize())")
{
    SUBCASE("Check stack after redefinition of the players"){

    Player p3("Avi");
    Player p4("Ofir");
    Game game2(p3, p4);
    CHECK(p3.stacksize() == 26);
    CHECK(p4.stacksize() == 26);
    }
    SUBCASE("Check stack after playAll function"){
    Player p1("Ofir");
    Player p2("Avi");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    }
}

TEST_CASE("Test 3 - Check card function working well")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    Card card = Card(Heart, Two, Black);
    p1.getPersonalStack().setTopCard(card);
    CHECK(p1.liftCard().getCard().getNumber() == card.getNumber());
    p2.getPersonalStack().takeAcard();
    CHECK(p2.stacksize() == 25);
}
TEST_CASE("Test 4 - Check war between 2 players")
{
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
TEST_CASE("Test 5 - Check tie (war) between p1 and p2")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    Card p1_card = Card(Heart, Two, Black);
    Card p2_card = Card(Heart, Two, Red);
    p1.getPersonalStack().setTopCard(p1_card);
    p2.getPersonalStack().setTopCard(p2_card);

    game.playTurn();

    CHECK(p1.stacksize() <= 23); // after a tie each player used at least 3 cards
    CHECK(p2.stacksize() <= 23);
}

TEST_CASE("Test 6 - Check full game - winner and ending status")
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
    CHECK(game.getWinner().cardesTaken() <= 52);
}
TEST_CASE("Test 7 - Check printLog")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    string log = game.getLog();
    stringstream log_stream;
    streambuf *logPrinted = cout.rdbuf();
    cout.rdbuf(log_stream.rdbuf());
    game.printLog();
    cout.rdbuf(logPrinted); // store the message printed from printWiner
    CHECK(log_stream.str() == log);
}
TEST_CASE("Test 8 - Check printStat")
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

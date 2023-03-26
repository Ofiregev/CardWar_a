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
}
TEST_CASE("Test 2 - Check stacksize during game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playTurn();
    CHECK(p1.stacksize() == 25);
    CHECK(p2.stacksize() == 25);
}
TEST_CASE("Test 3 - Check tie between p1 and p2")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    // Redirect the output stream to a stringstream
    std::stringstream ss;
    std::streambuf *oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Invoke the print function with input parameters 2 and 3
    game.printLastTurn();

    // Capture the output
    std::string output = ss.str();

    // Verify the output
    std::string expectedOutput = "The card is 5 heart Black\n";
    CHECK(output == expectedOutput);
    CHECK(output == expectedOutput);
    CHECK(output == "eee");
    CHECK(p2.stacksize() == 25);

    // Restore the original output stream
    std::cout.rdbuf(oldCout);
}

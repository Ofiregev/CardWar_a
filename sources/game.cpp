#include <iostream>
#include <string>
#include "game.hpp"
#include "player.hpp"
using namespace std;

namespace ariel
{
    Game::Game(Player p1, Player p2)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->last_turn = "startig game";
    }
    void Game::war(){
        Card p1_card = p1.liftCard();
        Card p2_card = p2.liftCard();

        if (p1_card.getNumber() > p2_card.getNumber())
        {
            p1.points = p1.points+1;
            this->setLastTurn(p1.get_name() + "played-"+ p1_card.toString() +"\n"+ p2.get_name() + "played-"+ p2_card.toString() +"."+ p1.get_name()+"win");
            p2.setCardsTaken(2);
        }
        else if(p2_card.getNumber() > p1_card.getNumber()){
            p2.points = p2.points+1;
            this->setLastTurn(p1.get_name() + "played-"+ p1_card.toString() +"\n"+ p2.get_name() + "played-"+ p2_card.toString() +"."+ p2.get_name()+"win");
            p1.setCardsTaken(2);
        }else{
            p1.getPersonalStack().takeAcard();
            p2.getPersonalStack().takeAcard();
            this->playTurn();
        }
    }
    void Game::printLastTurn()
    {
        cout << this->last_turn;
    }
    void Game::playAll()
    {
    }
    void Game::printWiner()
    {
    }
    void Game::printLog()
    {

    }
    void Game::printStats()
    {
        cout << p1.getStatus() + p2.getStatus();
    }
    void Game::playTurn() {
        this->war();

    }
    string Game::getLastTurn(){
        return this->last_turn;
    }
    void Game::setLastTurn(string last_turn){
        this->last_turn = last_turn;
    }
    Player Game::getWinner(){
        return this->winner;
    }
    void Game::setWinner(Player name){
        this->winner = name;
    }
     string Game::getLog(){
        return this->log;
    }
    void Game::setLog(string log){
        this->log = this->log + log;
    }



}

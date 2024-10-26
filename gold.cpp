#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold() : Event(){

  message = "You see a glimmer nearby.";
  letter = 'G';

}

char Gold::getEvent() const {
  return letter;
}

void Gold::setEvent(char symbol) {
  letter = symbol;
}

string Gold::getMessage() const {
  return message;
}

void Gold::setMessage(const string &msg) {
  message = msg;
}

void Gold::output_message(){
  cout << message << endl;
}

void Gold::encounter() const {
    cout << "You found a pile of gold! Congratulations!" << endl;
    // Implement the logic to increase the player's score or take other appropriate actions
    //game->player_gain_gold();
}

bool Gold::has_Gold() const {
  return letter;
}


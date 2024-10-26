#include "event.h"


using namespace std;

//Event Implementation

Event::Event(){
  string message = " ";
  char letter = ' ';
}

char Event::getEvent() const {
  return letter;
}

void Event::setEvent(char symbol) {
  letter = symbol;
}

string Event::getMessage() const {
  return message;
}

void Event::setMessage(const string &msg) {
  message = msg;
}

void Event::output_message(){
  cout << message << endl;
}

bool Event::has_Bats() const {
  return false;
}

bool Event::has_Stalactites() const {
  return false;
}

bool Event::has_Wumpus() const {
  return false;
}

bool Event::has_Gold() const {
  return false;
}

bool Event::has_Armor() const{
  return false;
}

bool Event::has_Passage() const {
  return false;
}

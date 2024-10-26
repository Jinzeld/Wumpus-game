#include "armor.h"


Armor::Armor() : Event() {
    message = "You feel the power.";
    letter = 'A';
}

char Armor::getEvent() const {
  return letter;
}

void Armor::setEvent(char symbol) {
  letter = symbol;
}

string Armor::getMessage() const {
  return message;
}

void Armor::setMessage(const string &msg) {
  message = msg;
}

void Armor::output_message(){
  cout << message << endl;
}

void Armor::encounter() const {
  cout << "I feel protected! " << endl;
}

bool Armor::has_Armor() const {
    return letter;
}
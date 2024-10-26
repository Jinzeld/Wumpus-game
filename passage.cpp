#include "passage.h"

#include <iostream>

using namespace std;

//Gold Implementation

Passage::Passage() : Event(){

  message = "You feel a breeze.";
  letter = '?';

}

char Passage::getEvent() const {
  return letter;
}

void Passage::setEvent(char symbol) {
  letter = symbol;
}

string Passage::getMessage() const {
  return message;
}

void Passage::setMessage(const string &msg) {
  message = msg;
}

void Passage::output_message(){
  cout << message << endl;
}

void Passage::encounter() const {
    cout << "You have be warped!: ";

}

bool Passage::has_Passage() const {
  return letter;
}


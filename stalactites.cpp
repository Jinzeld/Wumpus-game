#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

Stalactites::Stalactites() : Event(){

  message = "You hear water dripping. ";
  letter = 'S';
}

char Stalactites::getEvent() const {
  return letter;
}

void Stalactites::setEvent(char symbol){
  letter = symbol;
}

string Stalactites::getMessage() const {
  return message;
}

void Stalactites::setMessage(const string &msg) {
  message = msg;
}

void Stalactites::output_message(){
  cout << message << endl;
}

void Stalactites::encounter() const {
  cout << "you have encountered stalactites" << endl;
  
}

bool Stalactites::has_Stalactites() const {
  return letter;
}

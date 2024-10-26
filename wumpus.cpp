#include "wumpus.h"
#include <unistd.h>    

#include <iostream>

using namespace std;

//Wumpus Implementation

Wumpus::Wumpus() : Event(){
    message = "You smell a terrible stench. ";
    letter = 'W';
    hasWumpus = false;

}


char Wumpus::getEvent() const {
  return letter;
}

void Wumpus::setEvent(char symbol) {
 letter = symbol;
}

string Wumpus::getMessage() const {
  return message;
}

void Wumpus::setMessage(const string &msg) {
  message = msg;
}

void Wumpus::output_message(){
  cout << message << endl;
}

void Wumpus::encounter() const {
  cout << "You encountered Wumpus!" << endl;
    
}

bool Wumpus::has_Wumpus() const{
  return letter;
}

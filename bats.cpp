#include "bats.h"

using namespace std;

//Bats Implementation

Bats::Bats() : Event(){
    message = "You hear wings flapping.";
    letter = 'B';
    turnsOfConfusion = 0;

}

char Bats::getEvent() const {
  return letter;
}

void Bats::setEvent(char symbol) {
  letter = symbol;
}

string Bats::getMessage() const {
  return message;
}

void Bats::setMessage(const string &msg) {
  message = msg;
}

void Bats::output_message(){
  cout << message << endl;
}

void Bats::encounter() const {
    cout << "You encountered bats! your movements have been confused." << endl;
    // Implement any additional behavior specific to bats
}

bool Bats::has_Bats() const {
  return letter;
}

// void Bats::encounterSuperBats() const {
//     cout << "You are confused by Super Bats! Your controls are reversed for the next 5 moves." << endl;

// }

// bool Bats::encounterEffect() const {
//     cout << "You encountered bats! They whisk you away to a different location." << endl;

// }
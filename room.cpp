#include "room.h"

using namespace std;

//Room Implementation

Room::Room() : event(nullptr), hasPlayer(false), hasWumpus(false), row(0), col(0){
  row = 0;
  col = 0;
  hasEvent = false;
  hasPlayer = false;
  hasWumpus = false;
  event = nullptr;
  symbol = ' ';

}

Room::~Room(){
  clear_event();
}


void Room::clear_event(){

  if(event != nullptr){
    delete event;
    event = nullptr;
  }
}

// Implementation of the getter
Event* Room::getEvent() const {
  return this->event;
}

void Room::setEvent(Event* newEvent) {
 
  this->event = newEvent;
}

bool Room::event_exist() const {
  return event != nullptr;
}

bool Room::has_Player() const {
  return hasPlayer;
}

void Room::setPlayer(bool value) {
  hasPlayer = value;
}




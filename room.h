#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room 
{
private: 

  int row;
  int col;
  bool hasEvent;
  bool hasPlayer;
  bool hasWumpus;
  char symbol;
  Event* event;


public:

  Room();
  ~Room();
  

/**************************************************
 * Name: clear_event()
 * Description: clears the event pointer if its empty
 * Parameters: None
 * Pre-conditions: The Room object is valid.
 * Post-conditions: The pointer to the event in the room deletes
 ***********************************************/
void clear_event();

/**************************************************
 * Name: getEvent() const
 * Description: gets the pointer to the event in the room.
 * Parameters: None
 * Pre-conditions: The Room object is valid.
 * Post-conditions: The pointer to the event in the room is returned.
 ***********************************************/
  Event* getEvent() const;

/**************************************************
 * Name: setEvent(Event* newEvent)
 * Description: Sets the event in the room to the specified event pointer.
 * Parameters: Event* newEvent - the pointer to the new event
 * Pre-conditions: The Room object and the newEvent pointer are valid.
 * Post-conditions: The event in the room is set to the specified event pointer.
 ***********************************************/
  void setEvent(Event* newEvent);

/**************************************************
 * Name: event_exist() const
 * Description: Checks if there is an event in the room.
 * Parameters: None
 * Pre-conditions: The Room object is valid.
 * Post-conditions: Returns true if there is an event in the room, false otherwise.
 ***********************************************/
  bool event_exist() const;

/**************************************************
 * Name: event_exist() const
 * Description: Checks if there is an event in the room.
 * Parameters: None
 * Pre-conditions: The Room object is valid.
 * Post-conditions: Returns true if there is an event in the room, false otherwise.
 ***********************************************/
  bool has_Player() const;

/**************************************************
 * Name: setPlayer(bool value)
 * Description: Sets the player presence in the room to the specified value.
 * Parameters: bool value - the value to set for player presence
 * Pre-conditions: The Room object is valid.
 * Post-conditions: The player presence in the room is set to the specified value.
 ***********************************************/
  void setPlayer(bool value);


};

#endif
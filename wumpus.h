#ifndef WUMPUS_H
#define WUMPUS_H 
  

#include "event.h"

using namespace std;

//Wumpus Interface

class Wumpus : public Event {

protected:

int row;
int col;
bool hasWumpus;

public:

  Wumpus();

/**************************************************
 * Name: getEvent() const override
 * Description: Retrieves the symbol representing the Wumpus event.
 * Parameters: None
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: The symbol representing the Wumpus event is returned.
 ***********************************************/
  virtual char getEvent() const override;

/**************************************************
 * Name: setEvent(char symbol) override
 * Description: Sets the symbol representing the Wumpus event to the specified symbol.
 * Parameters: char symbol - the symbol to set for the Wumpus event
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: The symbol representing the Wumpus event is set to the specified symbol.
 ***********************************************/
  virtual void setEvent(char symbol) override;

/**************************************************
 * Name: getMessage() const
 * Description: Retrieves the message associated with the Wumpus event.
 * Parameters: None
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: The message associated with the Wumpus event is returned.
 ***********************************************/
  virtual string getMessage() const;

/**************************************************
 * Name: setMessage(const string &msg)
 * Description: Sets the message associated with the Wumpus event to the specified message.
 * Parameters: const string &msg - the message to set for the Wumpus event
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: The message associated with the Wumpus event is set to the specified message.
 ***********************************************/
  virtual void setMessage(const string &msg);

/**************************************************
 * Name: encounter() const override
 * Description: Performs the encounter action for the Wumpus event.
 * Parameters: None
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: The encounter action for the Wumpus event is executed.
 ***********************************************/
  virtual void encounter() const override;

/**************************************************
 * Name: output_message() override
 * Description: Outputs the message associated with the Wumpus event.
 * Parameters: None
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: The message associated with the Wumpus event is outputted.
 ***********************************************/
  virtual void output_message() override;

/**************************************************
 * Name: has_Wumpus() const override
 * Description: Checks if the event is a Wumpus event.
 * Parameters: None
 * Pre-conditions: The Wumpus object is valid.
 * Post-conditions: Returns true if the event is a Wumpus event, false otherwise.
 ***********************************************/
  virtual bool has_Wumpus() const override;
 


};


#endif
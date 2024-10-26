#ifndef ARMOR_H
#define ARMOR_H

#include "event.h"

#include <iostream>
#include <string>

using namespace std;

//Armor interface

class Armor : public Event {

protected:

public:
  Armor(); //Armor constructor

/**************************************************
 * Name: setEvent(char symbol) override
 * Description: Sets the symbol representing the Armor event to the specified symbol.
 * Parameters: char symbol - the symbol to set for the Armor event
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: The symbol representing the Armor event is set to the specified symbol.
 ***********************************************/
    virtual char getEvent() const override;

/**************************************************
 * Name: getEvent() const override
 * Description: Retrieves the symbol representing the Armor event.
 * Parameters: None
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: The symbol representing the Armor event is returned.
 ***********************************************/
    virtual void setEvent(char symbol) override;

/**************************************************
 * Name: getMessage() const override
 * Description: Retrieves the message associated with the Armor event.
 * Parameters: None
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: The message associated with the Armor event is returned.
 ***********************************************/
    virtual string getMessage() const override;

/**************************************************
 * Name: setMessage(const string &msg) override
 * Description: Sets the message associated with the Armor event to the specified message.
 * Parameters: const string &msg - the message to set for the Armor event
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: The message associated with the Armor event is set to the specified message.
 ***********************************************/
    virtual void setMessage(const string &msg) override;

  /**************************************************
 * Name: encounter() const override
 * Description: Performs the encounter action for the Armor event.
 * Parameters: None
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: The encounter action for the Armor event is executed.
 ***********************************************/
    virtual void encounter() const override;

/**************************************************
 * Name: output_message() override
 * Description: Outputs the message associated with the Armor event.
 * Parameters: None
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: The message associated with the Armor event is outputted.
 ***********************************************/
    virtual void output_message() override;

  /**************************************************
 * Name: has_Armor() const override
 * Description: Checks if the event is an Armor event.
 * Parameters: None
 * Pre-conditions: The Armor object is valid.
 * Post-conditions: Returns true if the event is an Armor event, false otherwise.
 ***********************************************/
    virtual bool has_Armor() const override;


};

#endif
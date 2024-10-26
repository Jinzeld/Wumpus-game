#ifndef BATS_H
#define BATS_H 

#include "event.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Bats Interface

class Bats : public Event { 

private:

    int turnsOfConfusion;
    
public:

    Bats();  // Constructor

/**************************************************
 * Name: setEvent(char symbol) override
 * Description: Sets the symbol representing the Bats event to the specified symbol.
 * Parameters: char symbol - the symbol to set for the Bats event
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: The symbol representing the Bats event is set to the specified symbol.
 ***********************************************/
    virtual void setEvent(char symbol) override;

/**************************************************
 * Name: getEvent() const override
 * Description: Retrieves the symbol representing the Bats event.
 * Parameters: None
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: The symbol representing the Bats event is returned.
 ***********************************************/
    virtual char getEvent() const override;

/**************************************************
 * Name: getMessage() const override
 * Description: Retrieves the message associated with the Bats event.
 * Parameters: None
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: The message associated with the Bats event is returned.
 ***********************************************/
    virtual string getMessage() const override;

/**************************************************
 * Name: setMessage(const string &msg) override
 * Description: Sets the message associated with the Bats event to the specified message.
 * Parameters: const string &msg - the message to set for the Bats event
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: The message associated with the Bats event is set to the specified message.
 ***********************************************/
    virtual void setMessage(const string &msg) override;

/**************************************************
 * Name: encounter() const override
 * Description: Performs the encounter action for the Bats event.
 * Parameters: None
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: The encounter action for the Bats event is executed.
 ***********************************************/
    virtual void encounter() const override;

/**************************************************
 * Name: output_message() override
 * Description: Outputs the message associated with the Bats event.
 * Parameters: None
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: The message associated with the Bats event is outputted.
 ***********************************************/
    virtual void output_message() override;

/**************************************************
 * Name: has_Bats() const override
 * Description: Checks if the event is a Bats event.
 * Parameters: None
 * Pre-conditions: The Bats object is valid.
 * Post-conditions: Returns true if the event is a Bats event, false otherwise.
 ***********************************************/
    virtual bool has_Bats() const override;
    
  
};

#endif
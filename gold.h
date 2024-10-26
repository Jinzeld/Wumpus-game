#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

#include <iostream>
#include <string>


using namespace std;

//Gold Interface

class Gold : public Event {

protected:

  string message;

public:

  Gold();

/**************************************************
 * Name: getEvent() const override
 * Description: Retrieves the symbol representing the Gold event.
 * Parameters: None
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: The symbol representing the Gold event is returned.
 ***********************************************/
    virtual char getEvent() const override;

/**************************************************
 * Name: setEvent(char symbol) override
 * Description: Sets the symbol representing the Gold event.
 * Parameters: char symbol - the symbol representing the Gold event
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: The symbol representing the Gold event is set.
 ***********************************************/
    virtual void setEvent(char symbol) override;

/**************************************************
 * Name: getMessage() const override
 * Description: Retrieves the message associated with the Gold event.
 * Parameters: None
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: The message associated with the Gold event is returned.
 ***********************************************/
    virtual string getMessage() const override;

/**************************************************
 * Name: setMessage(const string &msg) override
 * Description: Sets the message associated with the Gold event.
 * Parameters: const string &msg - the message to be set
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: The message associated with the Gold event is set.
 ***********************************************/
    virtual void setMessage(const string &msg) override;

/**************************************************
 * Name: encounter() const override
 * Description: Handles the encounter when a player interacts with the Gold event.
 * Parameters: None
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: The encounter with the Gold event is handled.
 ***********************************************/
    virtual void encounter() const override;

/**************************************************
 * Name: output_message() override
 * Description: Outputs the message associated with the Gold event.
 * Parameters: None
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: The message associated with the Gold event is output.
 ***********************************************/
    virtual void output_message() override;

/**************************************************
 * Name: has_Gold() const override
 * Description: Checks if the event is a Gold event.
 * Parameters: None
 * Pre-conditions: The Gold object is valid.
 * Post-conditions: Returns true if the event is a Gold event, false otherwise.
 ***********************************************/
    virtual bool has_Gold() const override;

};

#endif
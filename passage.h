#ifndef PASSAGE_H
#define PASSAGE_H 

#include "event.h"

#include <iostream>
#include <string>


using namespace std;

//Passage Interface

class Passage : public Event {

protected:


public:

  Passage();

/**************************************************
 * Name: getEvent() const override
 * Description: Retrieves the symbol representing the Passage event.
 * Parameters: None
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: The symbol representing the Passage event is returned.
 ***********************************************/
    virtual char getEvent() const override;

/**************************************************
 * Name: setEvent(char symbol) override
 * Description: Sets the symbol representing the Passage event.
 * Parameters: char symbol - the symbol representing the Passage event
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: The symbol representing the Passage event is set.
 ***********************************************/
    virtual void setEvent(char symbol) override;

/**************************************************
 * Name: getMessage() const override
 * Description: Retrieves the message associated with the Passage event.
 * Parameters: None
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: The message associated with the Passage event is returned.
 ***********************************************/
    virtual string getMessage() const override;

/**************************************************
 * Name: setMessage(const string &msg) override
 * Description: Sets the message associated with the Passage event.
 * Parameters: const string &msg - the message to be set
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: The message associated with the Passage event is set.
 ***********************************************/
    virtual void setMessage(const string &msg) override;

/**************************************************
 * Name: encounter() const override
 * Description: Handles the encounter when a player interacts with the Passage event.
 * Parameters: None
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: The encounter with the Passage event is handled.
 ***********************************************/
    virtual void encounter() const override;

/**************************************************
 * Name: output_message() override
 * Description: Outputs the message associated with the Passage event.
 * Parameters: None
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: The message associated with the Passage event is output.
 ***********************************************/
    virtual void output_message() override;

/**************************************************
 * Name: has_Passage() const override
 * Description: Checks if the event is a Passage event.
 * Parameters: None
 * Pre-conditions: The Passage object is valid.
 * Post-conditions: Returns true if the event is a Passage event, false otherwise.
 ***********************************************/
    virtual bool has_Passage() const override;

};

#endif
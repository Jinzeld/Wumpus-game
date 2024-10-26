#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

using namespace std;

//Stalactites Interface

class Stalactites : public Event{

protected:


public:

  Stalactites();

/**************************************************
 * Name: getEvent() const override
 * Description: Retrieves the symbol representing the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The symbol representing the event is returned.
 ***********************************************/
    virtual char getEvent() const override;

/**************************************************
 * Name: setEvent(char symbol) override
 * Description: Sets the symbol representing the event to the specified symbol.
 * Parameters: char symbol - the symbol to set for the event
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The symbol representing the event is set to the specified symbol.
 ***********************************************/
    virtual void setEvent(char symbol) override;


/**************************************************
 * Name: getMessage() const
 * Description: Retrieves the message associated with the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is returned.
 ***********************************************/
    virtual string getMessage() const;

/**************************************************
 * Name: setMessage(const string &msg)
 * Description: Sets the message associated with the event to the specified message.
 * Parameters: const string &msg - the message to set for the event
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is set to the specified message.
 ***********************************************/
    virtual void setMessage(const string &msg);

/**************************************************
 * Name: encounter() const override
 * Description: Performs the encounter action for the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The encounter action for the event is executed.
 ***********************************************/
    virtual void encounter() const override;

/**************************************************
 * Name: output_message() override
 * Description: Outputs the message associated with the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is outputted.
 ***********************************************/
    virtual void output_message() override;

/**************************************************
 * Name: has_Stalactites() const override
 * Description: Checks if the event is a stalactite event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: Returns true if the event is a stalactite event, false otherwise.
 ***********************************************/
    virtual bool has_Stalactites() const override;

};

#endif

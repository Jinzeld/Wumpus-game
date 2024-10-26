#ifndef EVENT_H
#define EVENT_H 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event {

protected:

    string message;
    char letter;
    
	
public:

    Event();
    virtual ~Event(){}
   
   /**************************************************
 * Name: setEvent(char symbol)
 * Description: Sets the symbol representing the event.
 * Parameters: char symbol - the symbol representing the event
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The symbol representing the event is set.
 ***********************************************/
    virtual void setEvent(char symbol) = 0;

/**************************************************
 * Name: getEvent() const
 * Description: Retrieves the symbol representing the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The symbol representing the event is returned.
 ***********************************************/
    virtual char getEvent() const = 0;  

/**************************************************
 * Name: getMessage() const
 * Description: Retrieves the message associated with the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is returned.
 ***********************************************/
    virtual string getMessage() const = 0;

/**************************************************
 * Name: setMessage(const string &msg)
 * Description: Sets the message associated with the event.
 * Parameters: const string &msg - the message to be set
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is set.
 ***********************************************/
    virtual void setMessage(const string &msg) = 0;

/**************************************************
 * Name: encounter() const
 * Description: Handles the encounter when a player interacts with the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The encounter with the event is handled.
 ***********************************************/
    virtual void encounter() const = 0; // player encounter function
    
/**************************************************
 * Name: output_message()
 * Description: Outputs the message associated with the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is output.
 ***********************************************/
    virtual void output_message() = 0;

/**************************************************
 * Name: output_message()
 * Description: Outputs the message associated with the event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: The message associated with the event is output.
 ***********************************************/
    virtual bool has_Bats() const;

/**************************************************
 * Name: has_Wumpus() const
 * Description: Checks if the event is a Wumpus event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: Returns true if the event is a Wumpus event, false otherwise.
 ***********************************************/
    virtual bool has_Wumpus() const; 

/**************************************************
 * Name: has_Wumpus() const
 * Description: Checks if the event is a Wumpus event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: Returns true if the event is a Wumpus event, false otherwise.
 ***********************************************/
    virtual bool has_Stalactites() const;

/**************************************************
 * Name: has_Gold() const
 * Description: Checks if the event is a Gold event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: Returns true if the event is a Gold event, false otherwise.
 ***********************************************/
    virtual bool has_Gold() const;

/**************************************************
 * Name: has_armor() const
 * Description: Checks if the event is an Armor event.
 * Parameters: None
 * Pre-conditions: The Event object is valid.
 * Post-conditions: Returns true if the event is an Armor event, false otherwise.
 ***********************************************/
    virtual bool has_Armor() const;
	

    virtual bool has_Passage() const;
};
#endif
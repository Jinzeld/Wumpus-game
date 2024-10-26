

/******************************************************
** Program: wumpus.cpp
** Author: Jinhui Zhen
** Date: 11/20/2023
** Description: Implementation of the "Hunt the Wumpus" game.
**              In this text-based adventure game, the player navigates through
**              a dark cave, encountering various events such as the Wumpus, bats,
**              stalactites, gold, and armor. The goal is to find and defeat the Wumpus
**              while avoiding fatal encounters. The game provides a thrilling
**              experience with random cave configurations and strategic decision-making.
**
** Input:   Player commands through keyboard input during gameplay.
** Output:  Display of game information, events, and outcomes on the console.
******************************************************/


#ifndef GAME_H
#define GAME_H 

#include "room.h"

#include <vector>
#include <iostream> 
#include <utility>
#include <unistd.h> 


using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector <vector<Room> >grid;
	vector<Event *> evtPtrs;
  vector<Room *> roomPtrs;
  Room* escape;
	Event* event;

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not

	//feel free to add more variables...

	int p_row;
	int p_col;
	int s_row;
	int s_col;
	bool gold ;
	bool armor;
	char last_input = ' ';
	int armorCount = 0;
	int num_moves_confused = 0;
	bool continuePlay;
	


public:

	//suggested functions:
	Game();
	~Game();


	/**************************************************
 * Name: set_up(int length, int width)
 * Description: Sets up the initial state of the game with the specified dimensions.
 * Parameters: int length - the length of the game grid, int width - the width of the game grid
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The game grid is initialized with dimensions, events are inserted, and player location is set.
 ***********************************************/
	void set_up(int, int);

	/**************************************************
 * Name: create_cave()
 * Description: Creates the initial structure of the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The game grid structure is created.
 ***********************************************/
	void create_cave();

	/**************************************************
 * Name: setup_input()
 * Description: Sets up the input parameters for the game.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: Input parameters such as dimensions and debug mode are set.
 ***********************************************/
	void setup_input();

	/**************************************************
 * Name: insert_events()
 * Description: Inserts events (Bats, Stalactites, Wumpus, Gold, Armor) randomly into the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: Events are randomly placed on the game grid.
 ***********************************************/
	void insert_events();

	/**************************************************
 * Name: placeEvent(Event* event)
 * Description: Randomly places the specified event on the game grid.
 * Parameters: Event* event - the event to be placed
 * Pre-conditions: The Game object is valid, and the event is initialized.
 * Post-conditions: The event is placed in a random room on the game grid.
 ***********************************************/
	void placeEvent(Event* event);

	/**************************************************
 * Name: setPlayerLocation(int p_row, int p_col)
 * Description: Sets the initial location of the player on the game grid.
 * Parameters: int p_row - the row coordinate, int p_col - the column coordinate
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player's location is set on the game grid.
 ***********************************************/
	void setPlayerLocation(int row, int col);

/**************************************************
 * Name: set_grid_size(int length, int width)
 * Description: Sets the size of the game grid.
 * Parameters: int length - the length of the game grid, int width - the width of the game grid
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The size of the game grid is set.
 ***********************************************/
	void set_grid_size(int length, int width);

	/**************************************************
 * Name: display_game() const
 * Description: Displays the current state of the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The current state of the game grid is displayed.
 ***********************************************/
	void display_game() const;

/**************************************************
 * Name: check_win() const
 * Description: Checks if the player has won the game.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: Returns true if the player has won, false otherwise.
 ***********************************************/
	bool check_win() const;

/**************************************************
 * Name: get_dir()
 * Description: Retrieves the direction input from the player.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The direction input is returned.
 ***********************************************/
	char get_dir();

	/**************************************************
 * Name: wumpus_move()
 * Description: Moves the Wumpus to a random adjacent room.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The Wumpus is moved to a random adjacent room.
 ***********************************************/
	void wumpus_move();

/**************************************************
 * Name: fire_arrow()
 * Description: Initiates the arrow-firing process in the game.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The arrow-firing process is initiated.
 ***********************************************/
	void fire_arrow();

	/**************************************************
 * Name: handle_Wumpus_hit(int row, int col)
 * Description: Handles the outcome when an arrow hits the Wumpus.
 * Parameters: int row - row coordinate of the arrow, int col - column coordinate of the arrow
 * Pre-conditions: The Game object is valid.
 * Post-conditions: Returns true if the arrow hits the Wumpus, false otherwise.
 ***********************************************/
	bool handle_Wumpus_hit(int row, int col);

/**************************************************
 * Name: move_up()
 * Description: Moves the player upward on the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player is moved upward on the game grid.
 ***********************************************/
	void move_up();

/**************************************************
 * Name: move_down()
 * Description: Moves the player downward on the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player is moved downward on the game grid.
 ***********************************************/
	void move_down();

	/**************************************************
 * Name: move_left()
 * Description: Moves the player to the left on the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player is moved to the left on the game grid.
 ***********************************************/
	void move_left();

	/**************************************************
 * Name: move_right()
 * Description: Moves the player to the right on the game grid.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player is moved to the right on the game grid.
 ***********************************************/
	void move_right();

	/**************************************************
 * Name: move(char c)
 * Description: Moves the player in the specified direction on the game grid.
 * Parameters: char c - the direction input
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player is moved in the specified direction on the game grid.
 ***********************************************/
	void move(char c);

	/**************************************************
 * Name: perceptions() const
 * Description: Displays the player's perceptions based on the current room.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player's perceptions are displayed.
 ***********************************************/
	void perceptions() const;

	/**************************************************
 * Name: player_encounter()
 * Description: Handles player encounters with events in the current room.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: Player encounters with events are handled.
 ***********************************************/
	void player_encounter();

	/**************************************************
 * Name: armor_encounter()
 * Description: Handles the player's encounter with the Armor event.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player's encounter with the Armor event is handled.
 ***********************************************/
	void armor_encounter();
	
	/**************************************************
 * Name: encounterPassage()
 * Description: teleports the player to a location
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: whem the player encounters the passage
 ***********************************************/
	void encounterPassage();
	
	/**************************************************
 * Name: check_confusion()
 * Description: Checks if the player is in a state of confusion.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player's confusion status is checked.
 ***********************************************/
	void check_confusion( );

	/**************************************************
 * Name: confused_move()
 * Description: Executes a move for the player when in a state of confusion.
 * Parameters: None
 * Pre-conditions: The Game object is valid, and the player is confused.
 * Post-conditions: The player makes a move in a random direction.
 ***********************************************/
	void confused_move( );

/**************************************************
 * Name: get_input()
 * Description: Retrieves the player's input for movement.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player's input for movement is returned.
 ***********************************************/
	char get_input();

/**************************************************
 * Name: play_game(int, int, bool)
 * Description: Initiates the gameplay with the specified dimensions and debug mode.
 * Parameters: int - the length of the game grid, int - the width of the game grid, bool - debug mode
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The gameplay is initiated with the specified parameters.
 ***********************************************/
	void play_game(int, int, bool);

	/**************************************************
 * Name: playAgain()
 * Description: Handles the option to play the game again after a game over.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The player's choice to play again is handled.
 ***********************************************/
	void playAgain();

	/**************************************************
 * Name: initializeGame()
 * Description: Initializes the game with the same cave configuration.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The game is initialized with the same cave configuration.
 ***********************************************/
	void initializeGame();

	/**************************************************
 * Name: initializeGameRandom()
 * Description: Initializes the game with a new random cave configuration.
 * Parameters: None
 * Pre-conditions: The Game object is valid.
 * Post-conditions: The game is initialized with a new random cave configuration.
 ***********************************************/
	void initializeGameRandom();
	


	

};
#endif
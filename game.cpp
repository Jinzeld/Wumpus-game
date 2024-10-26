
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

#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "armor.h"
#include "wumpus.h"
#include "passage.h"

#include <iostream>

//Game Implementation

Game::Game(){
	length = 0;
	width = 0;
	num_arrows = 0;
    num_moves_confused = 0;
	debug_view = false;
    gold = false;
    armor = false;
    continuePlay = true;

	grid = vector<vector<Room> >(length, vector<Room>(width)); 

}

Game::~Game() {
   grid.clear();
}

void Game::set_up(int l, int w) {
	// Set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; // Start with 3 arrows

	// Create the game board: 2D vector of Room objects
	create_cave();

	// Randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold) into the board
	insert_events();

	// Randomly place the player
	int playerRow, playerCol;
	do {
		playerRow = rand() % length;
		playerCol = rand() % width;
	} while (grid[playerRow][playerCol].getEvent() != nullptr); // Ensure the player is not in a room with an event

	setPlayerLocation(playerRow, playerCol);

    //saves the player location
    s_row = p_row;
    s_col = p_col;   

}


void Game::create_cave() { //creates the grid structure
    for (int i = 0; i < this->length; i++) {
        vector<Room> temp;
        for (int j = 0; j < this->width; j++) {
          temp.push_back(Room());
        }
        this->grid.push_back(temp);
    }
}


void Game::insert_events() {
   // Insert the events randomly
   for (int i = 0; i < 2; i++) {
      placeEvent(new Bats());
   }
  
   for (int i = 0; i < 2; i++) {
      placeEvent(new Stalactites());
   }

    for (int i = 0; i < 2; i++) {
        placeEvent(new Passage());
   }

   placeEvent(new Wumpus());

   placeEvent(new Gold());

   placeEvent(new Armor());

}


void Game::placeEvent(Event* event) { // randomizes the event placement on the grid
   int x, y;

   do {
      x = rand() % this->length;
      y = rand() % this->width;
   } while(grid[x][y].getEvent() != NULL); // Find an empty space in the grid

    // If an event exists in the room, delete it before assigning a new one
    if (grid[x][y].getEvent() != nullptr) {
        delete grid[x][y].getEvent();
    }

    grid[x][y].setEvent(event);
}


void Game::setPlayerLocation(int row, int col) { // set the player's location
	grid[row][col].setPlayer(1);
  //playerLocation = make_pair(row, col);
	p_row = row;
	p_col = col;
}

void Game::display_game() const{
    cout << endl << endl;
    cout << "Arrows remaining: " << this->num_arrows << endl;

    string line = "";
    for (int i = 0; i < this->width; ++i)
        line += "-----";

    for (int i = 0; i < this->length; ++i) {
        cout << line << endl;
        for (int j = 0; j < this->width; ++j) {
            // Check if the player is in the room
            if (grid[i][j].has_Player()) {
                cout << "*";
            } else {
                cout << " ";
            }

            // Check if the room has an event
            Event* roomEvent = grid[i][j].getEvent();
            if (roomEvent == nullptr) {
                // Room has no event
                cout << "  ||";
            } else {
                // Room has an event
                if (debug_view) {
                    // Display event type in debug view
                    cout << roomEvent->getEvent() << " ||";
                } else {
                    // Display space in regular view
                    cout << "  ||";
                }
            }
        }
        cout << endl;
    }
    cout << line << endl;

    //example output (when finished): 
    // --------------------
    //  B || G || B ||   ||
    // --------------------
    //    || W ||   || S ||
    // --------------------   
    //    ||   ||   || S ||
    // --------------------   
    // *  ||   ||   ||   ||
    // --------------------
}


bool Game::check_win() const{
	//check if game over/win
	//Your code here:
    if(p_row == s_row && p_col == s_col && gold){
        return true;
    }
    return false;
}


void Game::playAgain() {

    // If the player encounters the Wumpus and chooses to play again:
    cout << endl << "Do you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        
        
        cout << "---" << endl << "1. Restart with the same cave configuration" << endl;
        cout << "2. Restart with a new random cave configuration" << endl;
        cout << "3. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Restart with the same cave configuration
                initializeGame();
                continuePlay = true;
                break;

               
            case 2:
                // Restart with a new random cave configuration
                initializeGameRandom();
                continuePlay = true;
                break;
            case 3:
                // Quit the game
                continuePlay = false;
                break;
              

        }
    } else {
        cout << "Thanks for playing! Goodbye." << endl;
        //exit the game
        continuePlay = false;
        
    }
}


void Game::initializeGame() {
    // Reset game state variables
    num_arrows = 3;
    num_moves_confused = 0;
    gold = false;
    armor = false;

    // Clear existing events from memory and player
    grid[p_row][p_col].setPlayer(false);
    grid.clear();
    

    // Create the game board with the same cave configuration
    create_cave();

    // Insert events into the same positions
    insert_events();

    // Randomly place the player in a new position
    int playerRow, playerCol;
    do {
        playerRow = rand() % length;
        playerCol = rand() % width;
    } while (grid[playerRow][playerCol].getEvent() != nullptr);

    setPlayerLocation(playerRow, playerCol);

}

void Game::initializeGameRandom() {


    // Clear existing events from the grid
    grid[p_row][p_col].setPlayer(false);
    grid.clear();
    gold = false;
    armor = false;

    // Get user input for dimensions and debug mode
    int wid, len;
    bool debug = false;
    

    do {
        cout << "Please enter the number of width: ";
        cin >> wid;

        cout << "Please enter the number of length: ";
        cin >> len;

        // Check if the dimensions are within the allowed range (4 to 50)
        if (wid >= 4 && wid <= 50 && len >= 4 && len <= 50) {
            cout << "Valid dimensions entered." << endl;

        } else {
            cout << "Invalid dimensions. Please enter dimension between 4x4 and 50x50." << endl;
        }
    } while (wid < 4 || wid > 50 || len < 4 || len > 50);

    // Get the debug mode input with error handling
    cout << "Do you want debug mode (1 for yes, 0 for no): ";
    while (!(cin >> debug) || (debug != 0 && debug != 1)) {
        // Handle invalid input (non-integer or not 0 or 1)
        cout << "Invalid input. Please enter 0 for no or 1 for yes: ";
        cin.clear(); // Clear the error flag
        cin.ignore(256, '\n'); // Discard invalid input
    }

    // Play the game
    play_game(wid, len, debug);
}


// After updating player position in each move function (move_up, move_down, move_left, move_right),
// Check for events in the new player position and handle them
void Game::move_up() {
    // Move player up
    if (p_row > 0) {
        grid[p_row][p_col].setPlayer(false);
        p_row--;
        grid[p_row][p_col].setPlayer(true);
		setPlayerLocation(p_row, p_col);
        player_encounter();
        armor_encounter();
    } else {
        cout << "Can't move. Out of bound! ";
    }
}


void Game::move_down() {
    // Move player down
    if (p_row < length - 1) {
        grid[p_row][p_col].setPlayer(false);
        p_row++;
        grid[p_row][p_col].setPlayer(true);
		setPlayerLocation(p_row, p_col);
        player_encounter();
        armor_encounter();
    } else {
        cout << "Can't move. Out of bound! ";
    }
}


void Game::move_left() {
    // Move player left
    if (p_col > 0) {
        grid[p_row][p_col].setPlayer(false);
        p_col--;
        grid[p_row][p_col].setPlayer(true);
		setPlayerLocation(p_row, p_col);
        player_encounter();
        armor_encounter();
    } else {
        cout << "Can't move. Out of bound! ";
    }
}


void Game::move_right() {
    // Move player right
    if (p_col < width - 1) {
        grid[p_row][p_col].setPlayer(false);
        p_col++;
        grid[p_row][p_col].setPlayer(true);
		setPlayerLocation(p_row, p_col);
        player_encounter();
        armor_encounter();
    } else {
        cout << "Can't move. Out of bound! ";
    }
}


void Game::player_encounter(){ // handle events at the player's current position
    Event* event = grid[p_row][p_col].getEvent();
    perceptions();
  
    if (event != nullptr) {
        event->encounter();
        if (event->has_Armor()){
            armorCount = 2;
            armor = true;
            grid[p_row][p_col].setEvent(nullptr);
            delete event;
        }
    

        else if (event->has_Gold()){
            gold = true;
            grid[p_row][p_col].setEvent(nullptr); // removes gold after encountering it
            delete event;
        }

        else if (event->has_Bats()) {

            // checks if the player encounters the bat
            num_moves_confused = 5; 
        
        }

        else if(event->has_Passage()){
            encounterPassage();
        }

    }

    // if (grid[p_row][p_col].getEvent() != nullptr) {
    //     delete grid[p_row][p_col].getEvent();
    // }

}


void Game::armor_encounter() {
    Event* armor_event = grid[p_row][p_col].getEvent();

    if (armor_event != nullptr) {
        // There is an event in the room
        
        if (armor_event->has_Wumpus()){
            if (armorCount > 1) {
                cout << "Your armor protected you from the Wumpus!" << endl;
                armorCount--;
            } else {
                cout << "The Wumpus ate you alive! Game over." << endl;
                continuePlay = false;
                playAgain();
            } 

        }

        else if (armor_event->has_Stalactites()){
            int chance = rand() % 2; // 0 or 1

            if (armorCount > 0) {
                cout << "Your armor protected you from the Stalactites!" << endl;
                armorCount--;
                
            } else if(chance == 0 ){
                cout << "Stalactites fell on you! Game over." << endl;
        
                continuePlay = false;
                playAgain();
                
            }else{

                // The adventurer survived the stalactites encounter
                cout << "You narrowly avoided falling stalactites." << endl;
            }

            
        }
       
    }

}


void Game::encounterPassage(){

    // Move the player to the other room (opposite side of the cave)
        int other_row = length - 1 - p_row;
        int other_col = width - 1 - p_col;

        // Update the player's position
        grid[p_row][p_col].setPlayer(false);
        p_row = other_row;
        p_col = other_col;
        grid[p_row][p_col].setPlayer(true);

    // Display a message indicating the player has moved
    cout << "to another part of the cave!" << endl;
}


void Game::perceptions() const {

    // Check up
    if (p_row > 0) {
        Event* upEvent = grid[p_row - 1][p_col].getEvent();
        if (upEvent != nullptr) {
            cout << upEvent->getMessage() << endl;
        }
    }

    // Check down
    if (p_row < length - 1) {
        Event* downEvent = grid[p_row + 1][p_col].getEvent();
        if (downEvent != nullptr) {
            cout << downEvent->getMessage() << endl;
        }
    }

    // Check left
    if (p_col > 0) {
        Event* leftEvent = grid[p_row][p_col - 1].getEvent();
        if (leftEvent != nullptr) {
            cout << leftEvent->getMessage() << endl;
        }
    }

    // Check right
    if (p_col < width - 1) {
        Event* rightEvent = grid[p_row][p_col + 1].getEvent();
        if (rightEvent != nullptr) {
            cout << rightEvent->getMessage() << endl;
        }
    }
}


char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');


	return dir;
}


void Game::wumpus_move() {

    // Move the Wumpus to a neighboring room based on the chosen direction
    int x, y;

    do {
        x = rand() % this->length;
        y = rand() % this->width;
    } while (grid[x][y].getEvent() != nullptr); // Find an empty space in the grid

    // Update the Wumpus's position
    grid[x][y].setEvent(new Wumpus());  // Place Wumpus in the new room

    cout << "The Wumpus has moved to a different room!" << endl;

}


void Game::fire_arrow() {
    char dir = get_dir(); // Get the arrow direction from the player

    // Check if the player has run out of arrows
    if (num_arrows == 0) {
        cout << "You're out of arrows!" << endl;
        return; // Exit the function, as the player can't fire more arrows
    }

    int arrow_row = p_row;
    int arrow_col = p_col;
    bool hitWall = false;

    // Keep track of the arrow's path
    for (int i = 0; i < 3; ++i) {
        // Determine the path of the arrow based on the chosen direction
        switch (dir) {
            case 'w':
                if (arrow_row > 0) {
                    arrow_row--;
                } else {
                    hitWall = true;
                }
                break;

            case 's':
                if (arrow_row < length - 1) {
                    arrow_row++;
                } else {
                    hitWall = true;
                }
                break;

            case 'a':
                if (arrow_col > 0) {
                    arrow_col--;
                } else {
                    hitWall = true;
                }
                break;

            case 'd':
                if (arrow_col < width - 1) {
                    arrow_col++;
                } else {
                    hitWall = true;
                }
                break;

            default:
                cout << "Invalid direction!" << endl;
                break;
        }

        // Check for arrow collision in the current room
        if (handle_Wumpus_hit(arrow_row, arrow_col)) {
            // Arrow hit something, break out of the loop
            break;
        }
    }

    if (hitWall) {
        cout << "Arrow hit a wall or went out of bounds!" << endl;
    }

    num_arrows--; // Subtract the number of arrows
}


bool Game::handle_Wumpus_hit(int row, int col) {
    // Check for Wumpus or wall collision in the current room
    Event* currentEvent = grid[row][col].getEvent();

    if (currentEvent != nullptr) {
        // Assuming has_Wumpus() checks for the presence of Wumpus in the event
        int randomNum = rand() % 4; // Generate a random number for both hitChance

        if (currentEvent->has_Wumpus()) {
            // Randomly determine if the arrow hits the Wumpus (75% chance of missing)
            int hitChance = randomNum; 
            if (hitChance != 0) {
                cout << "You missed the Wumpus!" << endl;
                delete currentEvent;
                grid[row][col].setEvent(nullptr);
                wumpus_move(); 
                return true;
            } else {
                grid[row][col].setEvent(nullptr);
                delete currentEvent;
                cout << "You killed the Wumpus!" << endl;
                cout << "Congrats! You won. " << endl;
                playAgain();
                return true;
            }
        }
    } 

    return false; // no wumpus in room
}


void Game::move(char c) {
    // Handle player's action: move or fire an arrow
    if (c == 'f') {
        Game::fire_arrow();
        return;
    }

    // Check if the player is currently confused
    if (num_moves_confused > 0) {
        // Reverse the input direction
        switch (c) {
            case 'w':
                move_down(); // Update last_input
                break;
            case 'a':
                move_right();  // Update last_input
                break;
            case 's':
                move_up();  // Update last_input
                break;
            case 'd':
                move_left();  // Update last_input
                break;
        }

        num_moves_confused--;

        cout << "Remaining moves in confusion: " << num_moves_confused << endl;

    } else {
        // Handle normal movement
        switch (c) {
            case 'w':
                Game::move_up();
                break;
            case 'a':
                Game::move_left();
                break;
            case 's':
                Game::move_down();
                break;
            case 'd':
                Game::move_right();
                break;
            // Add additional cases if needed

        }
    }

}


char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:

	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: ";
	cin >> c;
	cin.ignore(256, '\n');
    //c = getch();

    
    // Update last_input
    last_input = c;

	
	return c;
}


void Game::play_game(int w, int l, bool d) {

    Game::set_up(w, l);
    
    this->debug_view = d;

    char input;

    while (true) {

        // Print game board
        Game::display_game();

        // Player move...
        // 1. Get input
        input = Game::get_input();

        // 2. Move player
        Game::move(input);

        // Check if winning conditions are true or not
        if (check_win() == true) {
            // Display win message and exit successfull
            cout << "Congratulations! You won!" << endl << endl;
            playAgain();
        
        }
        // Check if the player wants to play again
        if (continuePlay == false) {
            break;  // Exit the loop when the player chooses not to play again
        }
    }
}

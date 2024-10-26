#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid, len ;
	bool debug = false;
	
	Game g;

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

	//Play game
	g.play_game(wid, len, debug);


	return 0;
}
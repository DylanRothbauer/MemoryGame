#include "Game.h"

/*
* Dylan Rothbauer
* 2/20/23
* A classic memory game thats between two players
* where they take turns to match pairs of cards.
* 
* CHANGE LOG:
* 2/7/23 - Dylan Rothbauer - Added function comments
*/

// TEST FOR GIT

/*
* Test funciton of Memory War
*/
void runAllTests() {

	cout << "Running tests of the Game class..." << endl;

	cout << "Test 1: Constructor does not crash: " << endl << endl;
	try {
		Game g;

		if (g.getPairs() == 10) {
			cout << "SUCCESS." << endl;
		}
	}
	catch (...) {
		cout << "FAILED." << endl;
	}

	cout << endl;

	cout << "Test 2: Player who gets a pair goes again: ";
	try {
		Game g;

		g.clearIfMatch(0,0,2,2); // MATCH PAIR OF 1
		
		// Check if playerPtr == location of player1
		if (g.getPlayerPtr() == g.getPlayerOne()) {
			cout << "SUCCESS." << endl;
		}

	}
	catch (...) {
		cout << "FAILED." << endl;
	}

	cout << endl;

	cout << "Test 3: Player who doesn't get pair doesn't go again:";
	try {
		Game g;

		g.clearIfMatch(0, 0, 0, 1); // NOT A PAIR. (1) & (2)

		// Check if playerPtr == location of player2
		if (g.getPlayerPtr() == g.getPlayerTwo()) {
			cout << "SUCCESS." << endl;
		}
	}
	catch (...) {
		cout << "FAILED." << endl;
	}

	cout << endl;

	cout << "Test 4: A card that is flipped can not be accessed again:";
	try {
		Game g;

		g.clearIfMatch(0, 1, 2, 3); // A MATCH

		// Check if first location and second location is flipped, it cannot be accessed again
		if (g.getDeck()[0][1].getObtained() && g.getDeck()[2][3].getObtained()) {
			cout << "SUCCESS." << endl;
		}
	}
	catch (...) {
		cout << "FAILED." << endl;
	}

	cout << endl;

	cout << "Test 5: Check player gets right results from pairs:";
	try {
		Game g;

		// Matching (8) and (2) == 10!
		g.clearIfMatch(1, 3, 4, 1);
		g.clearIfMatch(0, 1, 2, 3);

		if (g.getPlayerOne()->getScore() == 10) {
			cout << "SUCCESS." << endl;
		}
	}
	catch (...) {
		cout << "FAILED." << endl;
		Game g;

		// Matching (8) and (2) == 10!
		g.clearIfMatch(1, 3, 4, 1);
		g.clearIfMatch(0, 1, 2, 3);

		cout << "Expected: 10 ... Actual: " << g.getPlayerOne()->getScore() << endl;
	}

	cout << endl;

	cout << "Test 6: Check for correct final screen by score:";
	try {
		Game g;

		// Check for correct final screen with score
		g.getPlayerOne()->addToScore(10);
		g.getPlayerTwo()->addToScore(7);

		// Expects Player1 to win!
		g.clearIfFinished();

		cout << endl << "SUCCESS." << endl;
	}
	catch (...) {
		cout << "FAILED." << endl;
	}

	cout << endl;

}

// MAIN ==================================================================================================================
// To Play - set debug to false
// To Test - set debug to true
int main() {

	bool debug = true;
	if (debug) {
		runAllTests();
	}
	else {
		Game g;
		g.startPlaying();
	}
	
	//return 0;
}

#pragma once
#include "Card.h"
#include <vector>
#include <iostream>

/*
* CHANGE LOG:
* 2/7/23 - Dylan Rothbauer - Added function comments
* 3/3/23 - Dylan Rothbauer - Added security check for negitive integer input
*/

/*
* Game holds Players and a deck of Cards
*/
class Game {

private:
	vector<vector<Card>> ourDeck; // The deck that will hold cards
	Player player1; // First player
	Player player2; // Second player
	int pairs = 10; // Number of pairs within a Game
	Player* playerPtr; // A pointer to a player to keep track of whose turn it is

public:
	/*
	* Game constructor that builds the deck
	*/
	Game() {
		Card card1A{ 1 };
		Card card2A{ 2 };
		Card card3A{ 3 };
		Card card4A{ 4 };
		Card card5A{ 5 };
		Card card6A{ 6 };
		Card card7A{ 7 };
		Card card8A{ 8 };
		Card card9A{ 9 };
		Card card10A{ 10 };
		Card card1B{ 1 };
		Card card2B{ 2 };
		Card card3B{ 3 };
		Card card4B{ 4 };
		Card card5B{ 5 };
		Card card6B{ 6 };
		Card card7B{ 7 };
		Card card8B{ 8 };
		Card card9B{ 9 };
		Card card10B{ 10 };

		vector<Card> row1 = { card1A,card2A,card3A,card4A };
		vector<Card> row2 = { card5A,card6A,card7A,card8A };
		vector<Card> row3 = { card9A,card10A,card1B,card2B };
		vector<Card> row4 = { card3B,card4B,card5B,card6B };
		vector<Card> row5 = { card7B,card8B,card9B,card10B };

		ourDeck.push_back(row1);
		ourDeck.push_back(row2);
		ourDeck.push_back(row3);
		ourDeck.push_back(row4);
		ourDeck.push_back(row5);

		// Set starting player to Player1
		playerPtr = &player1;
		
	}

	/*
	* Return number of pairs within the Game
	*/
	int getPairs() {
		return pairs;
	}

	/*
	* Checks if the 2 given locations are a match
	*	If they are a match
	*		- add number to players score
	*		- set pair of cards to obtained and pairs--
	*		- have player go again
	*	If they are not a match
	*		- next players turn
	*/
	void clearIfMatch(int x1, int y1, int x2, int y2) {

		if (ourDeck[x1][y1].getNum() == ourDeck[x2][y2].getNum()) {
			cout << endl << "YOU FOUND A MATCH!" << endl;
			cout << "THE PAIRS OF " << ourDeck[x1][y1].getNum() << " has been discovered! Good job! Go again!" << endl;
			cout << endl;
		
			// Add the score to player
			playerPtr->addToScore(ourDeck[x1][y1].getNum());

			// Set both cards to obtained
			ourDeck[x1][y1].setObtained();
			ourDeck[x2][y2].setObtained();
			
			// -1 to paris that are in the deck
			pairs--;

		}
		else {
			cout << endl << "YOU DID NOT FIND A MATCH!" << endl;
			cout << "First location was: " << ourDeck[x1][y1].getNum() << ", Second location was: " << ourDeck[x2][y2].getNum();
			cout << endl << endl;

			// Set players turn to opponent
			if (playerPtr == &player1) {
				playerPtr = &player2;
			}
			else {
				playerPtr = &player1;
			}
		}

	}

	/*
	* Outputs who wins after all cards have been obtained
	*/
	void clearIfFinished() {

		int player1Score = player1.getScore();
		int player2Score = player2.getScore();

		cout << endl << "----------RESULTS----------" << endl << "Well done! The game has finished!" << endl;

		if (player1Score > player2Score) {
			cout << "The winner is .... Player 1 with a score of " << player1.getScore() << "!" << endl;
			cout << "Player 2 score: " << player2.getScore() << endl << endl;
		}
		else {
			cout << "The winner is .... Player 2 with a score of " << player2.getScore() << endl;
			cout << "Player 1 score: " << player1.getScore() << endl << endl;
		}

		cout << "THANKS FOR PLAYING!" << endl;

	}

	/*
	* Starts playing the game
	*/
	void startPlaying() {

		cout <<  "\tWelcome to Memory War!" << endl;
		cout << "Your goal is to pick 2 locations of highest value!" << endl;
		cout << "Good luck! Lets begin!" << endl;

		while (pairs > 0) {

			// Row & Colmn A is first location
			// Row & Colmn B is second location
			int rowA{ 0 };
			int colmnA{ 0 };
			int rowB{ 0 };
			int colmnB{ 0 };

			printDeck();

			// Check whos turn and get location input
			if (playerPtr == &player1) {
				cout << "Player 1 turn: " << endl;
			}
			else {
				cout << "Player 2 turn: " << endl;
			}

			cout << "Pick your first location: " << endl;
			cout << "Row: ";
			cin >> rowA;
			while (rowA > 4 || rowA < 0) {
				cout << "Invalid number. Pick a number 0 through 4: ";
				cin >> rowA;
			}

			cout << "Colmn: ";
			cin >> colmnA;
			while (colmnA > 3 || colmnA < 0) {
				cout << "Invalid number. Pick a number 0 through 3: ";
				cin >> colmnA;
			}

			// If first location has already been discovered, have user go agian
			while (ourDeck[rowA][colmnA].getObtained()) {
				cout << "That card has already been discovered! Try again!" << endl;
				cout << "Pick your first location: " << endl;
				cout << "Row: ";
				cin >> rowA;
				while (rowA > 4) {
					cout << "Invalid number. Pick a number 0 through 4: ";
					cin >> rowA;
				}

				cout << "Colmn: ";
				cin >> colmnA;
				while (colmnA > 3 || colmnA < 0) {
					cout << "Invalid number. Pick a number 0 through 3: ";
					cin >> colmnA;
				}
			}

			cout << endl << "Pick your second location: " << endl;
			cout << "Row: ";
			cin >> rowB;
			while (rowB > 4 || rowB < 0) {
				cout << "Invalid number. Pick a number 0 through 4: ";
				cin >> rowB;
			}

			cout << "Colmn: ";
			cin >> colmnB;
			while (colmnB > 3 || colmnB < 0) {
				cout << "Invalid number. Pick a number 0 through 3: ";
				cin >> colmnB;
			}

			// If second location has already been discovered, have user go again
			while (ourDeck[rowB][colmnB].getObtained()) {
				cout << "That card has already been discovered! Try again!" << endl;
				cout << "Pick your second location: " << endl;
				cout << "Row: ";
				cin >> rowB;
				while (rowB > 4 || rowB < 0) {
					cout << "Invalid number. Pick a number 0 through 4: ";
					cin >> rowB;
				}

				cout << "Colmn: ";
				cin >> colmnB;
				while (colmnB > 3 || colmnB < 0) {
					cout << "Invalid number. Pick a number 0 through 3: ";
					cin >> colmnB;
				}
			}

			// Need to check if second location is the same as first position
			// If so, isMatch() would evaluate true cause the numbers are the same
			// This would result in adding false scoring
			while (rowA == rowB && colmnA == colmnB) {
				cout << "You can not choose same position! Try again!" << endl;
				cout << "Pick your second location: " << endl;
				cout << "Row: ";
				cin >> rowB;
				while (rowB > 4 || rowB < 0) {
					cout << "Invalid number. Pick a number 0 through 4: ";
					cin >> rowB;
				}

				cout << "Colmn: ";
				cin >> colmnB;
				while (colmnB > 3 || colmnB < 0) {
					cout << "Invalid number. Pick a number 0 through 3: ";
					cin >> colmnB;
				}
			}

			clearIfMatch(rowA, colmnA, rowB, colmnB);
		}

		clearIfFinished();
	}

	/*
	* Prints the deck of cards
	*/
	void printDeck() {

		cout << endl <<"\t" << "  0   1   2   3" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "\t" << i << " ";
			for (int k = 0; k < 4; k++) {
				Card temp = ourDeck[i][k];

				if (temp.getObtained()) {
					cout << " X" << "  ";
				}
				else {
					cout << "[]" << "  ";
				}
			}
			cout << endl << endl;
		}
	}

	// FOR TESTING
	Player* getPlayerPtr() {
		return playerPtr;
	}

	// FOR TESTING
	Player* getPlayerOne() {
		return &player1;
	}

	// FOR TESTING
	Player* getPlayerTwo() {
		return &player2;
	}

	// FOR TESTING
	vector<vector<Card>> getDeck() {
		return ourDeck;
	}

};

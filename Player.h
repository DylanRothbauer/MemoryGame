#pragma once

using namespace std;

/*
* CHANGE LOG:
* 2/7/23 - Dylan Rothbauer - Added function comments
*/

/*
* A Player that contains a score
*/
class Player {
private:
	int score;


public:
	/*
	* Default Constructor
	*/
	Player() {
		score = 0;
	}

	/*
	* Returns the score of the player
	*/
	int getScore() {
		return score;
	}

	/*
	* Adds a score to the player
	*/
	void addToScore(int x) {
		score += x;
	}

	// FOR TESTING
	bool operator==(const Player& rhs) {
		return (this == &rhs);
	}

};

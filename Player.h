#pragma once

using namespace std;

/*
* CHANGE LOG:
* 2/7/23 - Dylan Rothbauer - Added function comments
* 3/3/23 - Dylan Rothbauer - Added comment on private fields
*/

/*
* A Player that contains a score
*/
class Player {
private:
	int score; // Score for each player. Will be decider of who wins


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

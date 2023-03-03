#pragma once
#include "Player.h"

/*
* CHANGE LOG:
* 2/7/23 - Dylan Rothbauer - Added function comments
* 3/3/23 - Dylan Rothbauer - Added comments to all fields
*/

/*
* Creats a Card object with a number
*/
class Card {

private:
	int num; // Number associated with each card (its card face value)
	bool isObtained = false; // A boolean to keep track of if a card has been "flipped" over
	

public:
	/*
	* Default Constructor
	*/
	Card();

	/*
	* Overriding constructor to take an integer
	*	and set the card "face down"
	*/
	Card(int x) {
		num = x;
		isObtained = false;
	}

	/*
	* Returns the number on the card
	*/
	int getNum() {
		return num;
	}

	/*
	* Flips card over
	*/
	void setObtained() {
		isObtained = true;
	}

	/*
	* Returns if card is flipped over or not
	*/
	bool getObtained() {
		return isObtained;
	}


};

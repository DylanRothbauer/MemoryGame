#pragma once
#include "Player.h"

/*
* CHANGE LOG:
* 2/7/23 - Dylan Rothbauer - Added function comments
*/

/*
* Creats a Card object with a number
*/
class Card {

private:
	int num;
	bool isObtained = false;
	

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

/*
File      : SquareBlaster.cpp
Class     : COP 3003
Author    : Wilsen R. Maitre
Desc      : The user will try to destroy falling targets and the system will keep track of his/her score and health. 
Reference : https://www.sfml-dev.org/tutorials/2.5/ 
 */

#include <iostream>
#include "Game.h"

int main() {

	
	std::string other = "Wanna play again ?";

	Response response1, response2(other);
	std::cout << response1.getresponse() << "\n";
	std::cout << response2.getresponse() << "\n";

	//Init Game engine
	Game game;

	// Game Loop Closing the window
	while (game.running()) { // Kepps checking to make sure the window is open or not and close the application

		//update
		game.update();

		//render
		game.render();

	}

	return 0;
}

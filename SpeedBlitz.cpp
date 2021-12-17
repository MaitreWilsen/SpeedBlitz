/** @file   SpeedBlitz.cpp.
*   @brief  SpeedBlitz is the best solution to quick reflexes and more. Fast decisions typically mean more mistakes—this
*           efficient training regimen induces a general speeding of perceptual reaction times without decreased performance
*			accuracy.The user will try to destroy falling targets and the system will keep track of his/her score and health.
*  @author Wilsen R. Maitre.
*  @bugs No Known Bugs.
 */

#include <iostream>
#include "Game.h"

 //using namespace sf;

int main()
{



	std::string other = "Emotion and instinct cloud our strategic vision when there is no time for proper evaluation. \n- Author: Garry Kasparov \n --------------------------------------------------";
	copyQuote word;

	Response response1, response2(other);
	std::cout << response1.getresponse() << "\n";
	std::cout << response2.getresponse() << "\n";



	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	Game game;

	// Game loop closing the window
	// Kepps checking to make sure the window is open or not and close the application
	while (game.running() && !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}

	//End of application
	return 0;
}

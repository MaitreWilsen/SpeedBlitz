/** @file   Game.h.
*   @brief  The header file where all the prototype and classes are stored for proper coding practice and readability.
*   @author Wilsen R. Maitre.
*   @bugs No Known Bugs.
 */


#pragma once


#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

 /*
	 Class that acts as the game engine.
	 Wrapper class.
 */

 // LO1
class Game {
	// LO6
private:
	//Variables Window
	sf::RenderWindow* window; // Delete the window when you want
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();
	// LO6

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const; // While the window is running
	const bool getEndGame() const;

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
};


// Overload a constructor
// LO1
// LO1a

class Response {
	// LO6

private:
	std::string name;
	// LO6

public:

	// 1. your name
	// LO1b
	Response() {
		std::string word = "Time trouble ... Reduces us all to pure reflex and reaction, tactical play.";
		name = word;
	}

	// 2. default response
	// LO1b
	Response(std::string other) {
		name = other;
	}

	std::string getresponse() {
		return name;
	}

};

// Inheritance 
// LO1
// LO2
// Base class

class mainQuote {
	// LO6

public:
	mainQuote() {
		std::cout << "The worst enemy of the strategist is the clock.\n";
	}
};

// LO1
// Sub class inheriting from Base Class(mainQuote)
class copyQuote : public mainQuote {
	// Class copyQuote will utilize the public function mainQuote

};

#ifndef GAME_H
#define GAME_H

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

class Game {
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
class Response {

private:
	std::string name;

public:

	// 1. your name
	Response() {
		std::string word = "Time trouble ... Reduces us all to pure reflex and reaction, tactical play.";
		name = word;
	}

	// 2. default response
	Response(std::string other) {
		name = other;
	}

	std::string getresponse() {
		return name;
	}

};

// Inheritance 
class mainQuote {
public:
	mainQuote() {
		std::cout << "The worst enemy of the strategist is the clock.\n";
	}
};

class copyQuote : public mainQuote {
	// Class copyQuote will utilize the public function mainQuote

};

#endif // !GAME_H

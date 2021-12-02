#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <ctime> //Random
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game{

private:

	//Window Varible
	sf::RenderWindow* window; // Delete the window when you want
	sf::VideoMode videoMode;
	sf::Event event;

	//Mouse Position
	sf::Vector2i mouse_postion_window;

	//Game Logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;



	//Game Objects
	std::vector<sf::RectangleShape> enemy; // This will contain the enemy square keep track of how many their are
	sf::RectangleShape enemy;

	//Private Functions
	void initVariables();
	void initWindow();
	void initEnemies();

public:
	// Constructors / Destructors
	
	
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const; // While the window is running

	//Functions
	void spawnEnemy();
	void pollEvents();
	void update_mouse_positions();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();

};

class Response {

private:
	std::string name;

public:   
								
	// 1. your name
	Response() {
		std::string word = "I DON'T NEED TO GET A LIFE";
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
		std::cout << "REAL GAMERS NEVER DIE THEY RESPAWN!\n";
	}
};

class copyQuote : public mainQuote {

};

#endif // !GAME_H

#ifndef GAME_H
#define GAME_H
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

	//Private Functions
	void initVariables();
	void initWindow();

public:
	// Constructors / Destructors
	
	
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const; // While the window is running

	//Functions
	void pollEvents();
	void update();
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

#include <iostream>
#include "Game.h"


//Private Functions
void Game::initVariables(){
	this->window = nullptr;
}

void Game::initWindow(){
	// Creating a Window
	// Create a window ; videomode for sizing the window ((Width,Height), name of the window)
	this->window = new sf::RenderWindow(sf::VideoMode(900, 600), "Square Blaster");
}

//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
}

Game::~Game() {
	delete this->window;

}

// Accessors
const bool Game::running() const // While the window is running
{
	return this->window->isOpen();
}


// Functions -> update the game logic (keyboard input etc)
void Game::pollEvents()
{
	// Event Polling
	while (this->window->pollEvent(this->event)) { // Whenever the window gets an event its going to save it in the variable

		switch (this->event.type) {// Mouse click, etc
		case sf::Event::Closed: // When you click the close button it send an event with type close and close the window
			this->window->close();
			break;
		case sf::Event::KeyPressed: // Another way to close the window if the user press the esc key on the keyboard
			if (this->event.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
		}
	}
}

void Game::update(){
	this->pollEvents();
}

void Game::render(){ // Visualizing all the positon putting pixels on the screen

	/*
	     - clear old frame
		 - render objects
		 - display frame in window
		 Renders the game objects.
	*/

	sf::Font font;
	if (!font.loadFromFile("Fonts/ka1.ttf")) {
		std::cout << "Error loading file \n";
		system("pause");
	}

	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setString("GAME OVER " );
	text.setPosition(335.f, 267.f);

	this->window->clear(sf::Color::Blue); // Clear the screen With a blue color
	this->window->draw(text);
	this->window->display();
}

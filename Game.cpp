#include <iostream>
#include "Game.h"


//Private Functions
void Game::initVariables(){
	this->window = nullptr;

	//Game logic
	
	this->points = 0;
	this-> enemySpawnTimerMax = 1000.f;//How fast the enemies should spawn
	this->enemySpawnTimer = this->enemySpawnTimerMax; // Timer going to start at max value and then reset to zero
	this->maxEnemies = 5;


}

void Game::initWindow(){
	// Creating a Window
	// Create a window ; videomode for sizing the window ((Width,Height), name of the window)
	this->window = new sf::RenderWindow(sf::VideoMode(900, 600), "Square Blaster");
	this->window->setFramerateLimit(60); //Frame rate
}

void Game::initEnemies() {
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(50.f, 50.f)); // Enemy size
	this->enemy.setFillColor(sf::Color::Red); //Enemy color
	this->enemy.setOutlineColor(sf::Color::Red);
	this->enemy.setOutlineThickness(1.f);
}


//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game() {
	delete this->window;

}

// Accessors
const bool Game::running() const // While the window is running
{
	return this->window->isOpen();
}


void Game::spawnEnemy(){
	//Spawns enemies and sets their random colors and random positions

	this->enemy.setPosition(
		// Turning the value of the window into a integer first and then randomizing 
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))

	);

	this->enemy.setFillColor(sf::Color::Green);

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

void Game::update_mouse_positions(){
	// Update the mouse positions: The mouse position relative to the window
	this->mouse_postion_window = sf::Mouse::getPosition(*this->window);
}

void Game::updateEnemies(){
	//Updating the timer for enemies spawning when the total amount od enemies is smaller than the maxium

	
	if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
		// Spawn the enemy and reset the timer
		this->spawnEnemy();
		this->enemySpawnTimer = 0.f;
	}
	else {
		this->enemySpawnTimer += 1.f;
	}

	//Move the enemies

}

void Game::update(){
	this->pollEvents();
	this->update_mouse_positions();
	this->updateEnemies();

}

void Game::renderEnemies(){

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

	this->window->clear(sf::Color::Blue);// Clear the screen With a blue color
	this->window->draw(this->enemy);

	this->window->draw(text);
	this->renderEnemies();
	this->window->display();
}

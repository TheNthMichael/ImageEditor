#pragma once
#include "includes.h"

/* class Application

 #### Wrapper class for all application functions


*/

class Application
{
private:
	// Var
	// Window
	sf::RenderWindow* window;		// Store a reference to the window for easy access
	sf::VideoMode videoMode;
	sf::Event ev;
	// Private Methods
	void initializeVar();
	void initWindow();
	void initBlocks();

	// Game Objects
	// sf::Sprite used for textures
	sf::RectangleShape block;


public:
	// Default Constructor and Destructor
	Application();
	virtual ~Application();

	// Mutators and Accessors
	const bool running() const;

	// Public Methods
	void pollEvents();
	void update();
	void render();

};


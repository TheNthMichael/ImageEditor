#include "Application.h"

// ########### Private Methods

void Application::initializeVar()
{
	this->window = nullptr;
}

void Application::initWindow() 
{
	// Set window size
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	// this->videoMode.getDesktopMode()  => Use to dynamically set the window to your screens size
	this->window = new sf::RenderWindow(this->videoMode, "MirnySl0w", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

// Initializes some game objects
void Application::initBlocks()
{
	// move, scale, rotate, fill color, origin, and set texture are all important methods/attributes
	this->block.setPosition(sf::Vector2f(10.f,10.f));
	this->block.setSize(sf::Vector2f(100.f, 100.f));		// 100.f ensures this is declared as a float. Also certain properties require sf::Vector2f
	this->block.setScale(sf::Vector2f(0.5f, 0.5f));
	this->block.setFillColor(sf::Color::Cyan);
	this->block.setOutlineColor(sf::Color::Cyan);
	this->block.setOutlineThickness(1.f);
}


// ########### Public Methods

// Default Constructor
Application::Application() {
	this->initializeVar();
	this->initWindow();
	this->initBlocks();
}

// Destructor
Application::~Application() {
	delete this->window;
}

// Mutators and Accessors
const bool Application::running() const
{
	return this->window->isOpen();
}

// Functions


void Application::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			default:
				break;
		}
	}
}

// Updates the application state every frame
void Application::update()
{
	this->pollEvents();

	// Relative to screen
	// std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl;

	// Relative to window

	// Move Block
	float x = sf::Mouse::getPosition(*this->window).x - (this->block.getSize().x * this->block.getScale().x / 2);
	float y = sf::Mouse::getPosition(*this->window).y - (this->block.getSize().y * this->block.getScale().y / 2);
	this->block.setPosition(sf::Vector2f(x,y));
	std::cout << "Mouse Position: " << sf::Mouse::getPosition(*this->window).x << ", " << sf::Mouse::getPosition(*this->window).y << std::endl;

}

/*
	@return void

	 - clear old frame
	 - render new objects
	 - display to window
	Renders the application
	*/
void Application::render()
{
	this->window->clear();

	// render objects
	this->window->draw(this->block);

	this->window->display();
}

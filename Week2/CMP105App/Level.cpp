#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circl.setRadius(100);
	circl.setPosition(sf::Vector2f(0, 0));
	circl.setFillColor(sf::Color::Black);
	circl.setOrigin(sf::Vector2f(100, 100));

	if (!f.loadFromFile("font/arial.ttf")) { std::cout << "Font load error \n"; }

	mouseMsg.setPosition(sf::Vector2f(0, 0));
	mouseMsg.setFillColor(sf::Color::Black);
	mouseMsg.setFont(f);
	mouseMsg.setCharacterSize(16);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W)) { std::cout << "W is pressed \n"; }
	if (input->isKeyDown(sf::Keyboard::J) & input->isKeyDown(sf::Keyboard::K) & input->isKeyDown(sf::Keyboard::L)) { std::cout << "J,K and L pressed \n"; }
	if (input->isKeyDown(sf::Keyboard::Escape)) { window->close(); }
	if (input->isMouseLDown()) { if (mouseFirstDown) { mouseFirstDownPos = sf::Vector2i(input->getMouseX(), input->getMouseY()); mouseFirstDown = false; } }
	else 
	{
		if (!mouseFirstDown)
		{
			mouseFirstDownPos = mouseFirstDownPos - sf::Vector2i(input->getMouseX(), input->getMouseY());
			std::cout << "Mouse drag distance = " << std::hypot(mouseFirstDownPos.x,mouseFirstDownPos.y) << std::endl;
			mouseFirstDown = true;
		}
	}

	if (input->isMouseRDown()) { circl.setPosition(sf::Vector2f(input->getMouseX(), input->getMouseY())); }

	mouseMsg.setString("(" + std::to_string(input->getMouseX()) + "," + std::to_string(input->getMouseY()) + ")");
}

// Update game objects
void Level::update()
{
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mouseMsg);
	window->draw(circl);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
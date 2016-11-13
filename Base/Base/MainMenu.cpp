#include "MainMenu.h"



MainMenu::MainMenu()
{
	title = "";
	button = ButtonManager();
}

MainMenu::MainMenu(std::string name):title(name)
{
	button = ButtonManager();
	button.AddButton("quit", sf::Vector2f(30, 30), "Assets/Sprites/button.png");
	button.AddButton("game", sf::Vector2f(30, 200), "Assets/Sprites/button.png");
	
}

std::string MainMenu::update(sf::RenderWindow & window)
{
	message=button.update(window);
	return message;
}


void MainMenu::draw(sf::RenderWindow & window)
{
	button.draw(window);
}

MainMenu::~MainMenu()
{
}

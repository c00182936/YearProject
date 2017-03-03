#include "MainMenu.h"


/////////////////////////
//default constructor
//////////////////////////
MainMenu::MainMenu()
{
	title = "";
	button = ButtonManager();
}
//////////////////////////
//used constructor, takes a title for the screen, adds two buttons
//////////////////////////
MainMenu::MainMenu(std::string name):title(name)
{
	button = ButtonManager();
	button.AddButton("quit", sf::Vector2f(30, 30), "Assets/Sprites/button.png");
	button.AddButton("game", sf::Vector2f(30, 200), "Assets/Sprites/button.png");
	
}
////////////////////////////////
// update loop
////////////////////////////////
std::string MainMenu::update(sf::RenderWindow & window)
{
	message=button.update(window);
	return message;
}

///////////////////////////////
//draw method
///////////////////////////////
void MainMenu::draw(sf::RenderWindow & window)
{
	button.draw(window);
}
///////////////////////////////
//main menu destructor
//////////////////////////////
MainMenu::~MainMenu()
{
}

#include "ScreenManager.h"



//ScreenManager::ScreenManager()
//{
//	window.create(sf::VideoMode(1280, 720), "My window");
//}

ScreenManager::ScreenManager()
{

}

ScreenManager::ScreenManager(sf::RenderWindow &win) :window(&win)
{
	//list.push_back(menu);
	
	currentScreen = "mainMenu";
	menu = MainMenu("mainMenu");
}

void ScreenManager::update()
{
	//will make if statements to see which screen to update
	//bascially there is a string in the screenmanager "currentscreen" which
	//will be the name of the curren screen that's running.
	//have a series of if statements or other conditions that will stop the drawing 
	//and updating of other screens if the currentscreen doesn't match.
	//no fucking about with inheritance and vectors
	//will also impliment a message system, will probably end up running through that background manager.
	//will handle events like game overs or qquits, or sound effects or something
	if(currentScreen=="mainMenu"){
		message=menu.update(*window); 
	}
	else if (currentScreen == "game")
	{
		message = screen.update(*window);
	}
	



	checkStringCases();
}

void ScreenManager::draw()
{
	if (currentScreen == "mainMenu") {
		menu.draw(*window);
	}
	else if (currentScreen == "game")
	{
		screen.draw(*window);
	}
}

void ScreenManager::checkStringCases()
{
	if (message =="quit")
	{
		window->close();
	}
	if (message == "game")
	{
		currentScreen = "game";
	}
	if (message == "mainMenu")
	{
		currentScreen == "mainMenu";
	}
}


ScreenManager::~ScreenManager()
{
}

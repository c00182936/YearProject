#pragma once
#include "GameScreen.h"
#include "ButtonManager.h"
class MainMenu
{
private:
	///instance of the button manager
	ButtonManager button;
	///a message to be passed back
	std::string message;


public:
	//////////////////////////////////
	//\brief the default constructor
	//
	//\param none
	/////////////////////////////////
	MainMenu();
	//////////////////////////////////
	//\brief the used contructor
	//
	//\param a name to pass back
	/////////////////////////////////
	MainMenu(std::string name);
	//////////////////////////////////
	//\brief update loop
	//
	//\param reference to the render window
	/////////////////////////////////
	std::string update(sf::RenderWindow & window);
	//////////////////////////////////
	//\brief draw loop
	//
	//\param reference of the render window
	/////////////////////////////////
	void draw(sf::RenderWindow & window);
	//////////////////////////////////
	//\brief destructor
	//
	//\param none
	/////////////////////////////////
	~MainMenu();
	/// title of the screen
	std::string title;
};


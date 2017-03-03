#pragma once
#include "MenuButton.h"
#include <vector>
#include<iostream>
#include <string>
class ButtonManager
{
private:
	///vector of buttons
	std::vector<MenuButton> ButtonVector;

	///current mouse position
	sf::Vector2f mousePos;
	///font for buttons
	sf::Font buttonFont;
	///tect for buttons
	sf::Text buttonTexts;
	///current message to be returned
	std::string currentMessage;
	///temp instance of the button 
	MenuButton temp;
public:
	//////////////////////////////////
	//\brief defualt constructor
	//
	//\param none
	/////////////////////////////////
	ButtonManager();
	//////////////////////////////////
	//\brief update loop
	//
	//\param reference of the render window
	/////////////////////////////////
	std::string update(sf::RenderWindow &win);
	//////////////////////////////////
	//\brief draw method
	//
	//\param reference of the render window
	/////////////////////////////////
	void draw(sf::RenderWindow &win);
	//////////////////////////////////
	//\brief selecting a button when clicked
	//
	//\param none
	/////////////////////////////////
	std::string SelectButton();
	//////////////////////////////////
	//\brief adds a button to the button vector
	//
	//\param title of the button, position and  the location
	/////////////////////////////////
	void AddButton(std::string title, sf::Vector2f position, std::string location);
	//////////////////////////////////
	//\brief destructor
	//
	//\param none
	/////////////////////////////////
	~ButtonManager();
};


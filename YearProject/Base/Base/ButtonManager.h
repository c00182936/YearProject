#pragma once
#include "MenuButton.h"
#include <vector>
#include<iostream>
#include <string>
class ButtonManager
{
private:
	std::vector<MenuButton> ButtonVector;
	sf::Vector2f mousePos;
	sf::Font buttonFont;
	sf::Text buttonTexts;
	std::string currentMessage;
	MenuButton temp;
public:
	ButtonManager();
	std::string update(sf::RenderWindow &win);
	void draw(sf::RenderWindow &win);
	std::string SelectButton();
	void AddButton(std::string title, sf::Vector2f position, std::string location);
	~ButtonManager();
};


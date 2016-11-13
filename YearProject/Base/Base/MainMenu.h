#pragma once
#include "GameScreen.h"
#include "ButtonManager.h"
class MainMenu
{
private:
	ButtonManager button;
	std::string message;
	sf::Sprite spr;
	sf::Texture tex;
public:
	MainMenu();
	MainMenu(std::string name);
	std::string update(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	~MainMenu();
	std::string title;
};


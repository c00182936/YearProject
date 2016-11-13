#pragma once
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include "MainMenu.h"

class ScreenManager
{//will manage and iterate between screens
private:	
	sf::RenderWindow * window;
	MainMenu menu;
	GameScreen screen;
	std::string currentScreen;
	std::string message;
	//std::vector<GameScreen> list;
	//not working yet, will make it so that the there will be a current screen that'll be updated
public:
	ScreenManager();
	ScreenManager(sf::RenderWindow &win);
	void update();
	void draw();
	void checkStringCases();
	~ScreenManager();
};


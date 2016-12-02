#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonManager.h"
#include "Crystal.h"
#include <vector>
#include <assert.h>
#include"Colour.h"

class GameScreen
{
private:
	ButtonManager button;
	std::vector< std::vector<Crystal> > grid;
	sf::Sprite cursor;
	sf::Texture cursorTex;
	sf::Vector2i cursorPosition;
	sf::Vector2i tileToSwap;
	void GameScreen::SwapTileWithoutCheck(sf::Vector2i dir);
	bool keydown;
	bool swapMode;
	int gridCols;
	int gridRows;
	void resetChecked();
	void MarkChecked();
public:
	GameScreen();
	GameScreen(int gridHeight, int gridWidth);
	std::string update(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	~GameScreen();
	std::string title;
	void CheckMatch(sf::Vector2i check);
	void SwapTile(sf::Vector2i dir);
	bool compareTiles(Crystal & a, Crystal & b);
};


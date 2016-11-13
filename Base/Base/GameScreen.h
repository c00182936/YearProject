#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonManager.h"
#include "Crystal.h"
#include <vector>
class GameScreen
{
private:
	ButtonManager button;
	std::vector< std::vector<Crystal> > grid;
	sf::Sprite cursor;
	sf::Texture cursorTex;
	sf::Vector2i cursorPosition;
	sf::Vector2i tileToSwap;
	bool keydown;
	bool swapMode;
	int gridCols;
	int gridRows;
public:
	GameScreen(int gridHeight = 5, int gridWidth = 5);
	std::string update(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	~GameScreen();
	std::string title;
	void CheckMatch();
	void SwapTile(sf::Vector2i dir);
	bool compareTiles(Crystal & a, Crystal & b);
};


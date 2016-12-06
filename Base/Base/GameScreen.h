#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonManager.h"
#include "HudManager.h"
#include "Crystal.h"
#include "Player.h"
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
	void GameScreen::SwapTileWithoutCheck(sf::Vector2i dir, sf::Vector2i pos);
	bool keydown;
	bool swapMode;
	int gridCols;
	int gridRows;
	void resetChecked();

	void MarkChecked();


	HudManager hud;
	Player p1;

public:
	GameScreen();
	GameScreen(int gridHeight, int gridWidth);
	std::string update(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	~GameScreen();
	std::string title;
	std::pair<Colour, int> CheckMatch(sf::Vector2i check);
	void SwapTile(sf::Vector2i dir);
	bool compareTiles(Crystal & a, Crystal & b);
};


#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonManager.h"
#include "HudManager.h"
#include "Crystal.h"
#include "Player.h"
#include <vector>
#include <assert.h>
#include"Colour.h"
#include <SFML/System/Clock.hpp>

class GameScreen
{
private:
	ButtonManager button;
	std::vector< std::vector<Crystal> > grid;
	std::vector< std::vector<Crystal> > prevGrid;
	sf::Sprite cursor;
	sf::Sprite crystals;
	sf::Texture crystalSheet;
	sf::Texture cursorTex;
	sf::Vector2i cursorPosition;
	sf::Vector2i tileToSwap;
	sf::Vector2i tileToSwap2;
	sf::Clock clock;

	void GameScreen::SwapTileWithoutCheck(sf::Vector2i dir, sf::Vector2i pos);
	bool keydown;
	bool swapMode;
	int gridCols;
	int gridRows;
	void resetChecked();
	void resetNull();
	void updatePrevious();
	void reverse();

	void MarkChecked();
	void swapFinished(sf::Vector2i pos1, sf::Vector2i pos2);
	void removeFinished(sf::Vector2i pos);

	HudManager hud;
	Player p1;

public:
	GameScreen();
	GameScreen(int gridHeight, int gridWidth);
	std::string update(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	int getScoreFromPlayer();
	~GameScreen();
	std::string title;
	std::pair<Colour, int> CheckMatch(sf::Vector2i check);
	void SwapTile(sf::Vector2i dir);
	bool compareTiles(Crystal & a, Crystal & b);
};


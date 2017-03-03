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
	
	///the grid displayed on screen
	std::vector< std::vector<Crystal> > grid;

	///the previous grid, used in a powerup
	std::vector< std::vector<Crystal> > prevGrid;
	///the cursor to show which tile is selected
	sf::Sprite cursor;
	sf::Texture cursorTex;
	///the position of the cursor on the grid
	sf::Vector2i cursorPosition;

	///the spritesheet of tiles to display and its sprite
	sf::Sprite crystals;	
	sf::Texture crystalSheet;

	///two coordinates on the grid, used for swapping tiles
	sf::Vector2i tileToSwap;
	sf::Vector2i tileToSwap2;

	///the clock used in an update
	sf::Clock clock;
	///the current amount of tile types available 
	int level = 3;

	///////////////////////////////
	//\brief swapping method that doesn't compare tiles to match (depreciated)
	//
	//\param direction to swap tiles and the initial tile to swap
	//////////////
	void GameScreen::SwapTileWithoutCheck(sf::Vector2i dir, sf::Vector2i pos);

	///boolean to ensure the cursor doesn't move too quickly
	bool keydown;
	///boolean to check whether to swap tiles or move the cursor
	bool swapMode;
	///number of rows and columns in the grid
	int gridCols;
	int gridRows;

	//////////////////////////////////
	//\brief resets tiles in the grid, ensure they aren't checked for removal
	//
	//\param none
	/////////////////////////////////
	void resetChecked();
	//////////////////////////////////
	//\brief resets null(removed) tiles, to a random tile
	//
	//\param none
	/////////////////////////////////
	void resetNull();
	//////////////////////////////////
	//\brief updates the previous grid
	//
	//\param none
	/////////////////////////////////
	void updatePrevious();
	//////////////////////////////////
	//\brief assigns the previous grid to the current one
	//
	//\param none
	/////////////////////////////////
	void reverse();
	//////////////////////////////////
	//\brief marks the checked tiles for removal
	//
	//\param none
	/////////////////////////////////
	void MarkChecked();
	//////////////////////////////////
	//\brief code to end the swapping animation and swap the tiles
	//
	//\param the positions of two tiles to swap
	/////////////////////////////////
	void swapFinished(sf::Vector2i pos1, sf::Vector2i pos2);
	//////////////////////////////////
	//\brief code to end the removing animation and remove the tiles
	//
	//\param the position of the tile to remove
	/////////////////////////////////
	void removeFinished(sf::Vector2i pos);

	///instance of the hud

	HudManager hud;
	///instance of the player container
	Player p1;

public:
	//////////////////////////////////
	//\brief default constructor
	//
	//\param none
	/////////////////////////////////
	GameScreen();
	//////////////////////////////////
	//\brief proper constructor
	//
	//\param takes the height and width of the grid
	/////////////////////////////////
	GameScreen(int gridHeight, int gridWidth);
	//////////////////////////////////
	//\brief update loop
	//
	//\param returns a string for a message, accepts a reference to renderwindow
	/////////////////////////////////
	std::string update(sf::RenderWindow & window);
	//////////////////////////////////
	//\brief draw method
	//
	//\param an instance of the renderwindow
	/////////////////////////////////
	void draw(sf::RenderWindow & window);
	//////////////////////////////////
	//\brief returns a score from the player container
	//
	//\param returns an integer
	/////////////////////////////////
	int getScoreFromPlayer();
	//////////////////////////////////
	//\brief destructor function
	//
	//\param none
	/////////////////////////////////
	~GameScreen();
	//////////////////////////////////
	//\brief checks for matches, by iterating in 4 directions from the starting position
	//
	//\param the direction of the match, the position is found from the current position variable
	/////////////////////////////////
	std::pair<Colour, int> CheckMatch(sf::Vector2i check);
	//////////////////////////////////
	//\brief swaps two tiles
	//
	//\param the direction of the swap
	/////////////////////////////////
	void SwapTile(sf::Vector2i dir);
	//////////////////////////////////
	//\brief compares two tiles to see if they match
	//
	//\param the two crystals
	/////////////////////////////////
	bool compareTiles(Crystal & a, Crystal & b);
};


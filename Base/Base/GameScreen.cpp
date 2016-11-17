#include "GameScreen.h"

GameScreen::GameScreen(int gridHeight, int gridWidth) : gridCols(gridHeight), gridRows(gridWidth)
{
	std::vector<Crystal> temp;
	sf::Vector2f tempPos(40,40);
	cursorPosition = sf::Vector2i(1, 1);
	cursor.setScale(0.5, 0.5);
	if (!cursorTex.loadFromFile("Assets/Sprites/selector.png"))
	{

	}
	for (int i = 0; i < gridCols; i++)
	{
		temp.clear();
		for (int j = 0; j < gridRows; j++)
		{
			temp.push_back(Crystal(tempPos));
			tempPos += sf::Vector2f(0, 50);
			//grid[i][j] = new Crystal();
		}
		grid.push_back(temp);
		tempPos += sf::Vector2f(50, -gridWidth*50);
	}
}

std::string GameScreen::update(sf::RenderWindow & window)
{
	if (keydown == false) {
		//Movement keys change function depending on mode.
		//In Move Mode, arrow keys move the cursor around the board.
		//In Swap Move, arrow keys selects a tile to switch with.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{//Move/Swap Left
			if (cursorPosition.x > 0) {
				if (swapMode == true)
				{
					SwapTile(sf::Vector2i(-1,0));
				}
				else
				cursorPosition += sf::Vector2i(-1, 0);
			}
			keydown = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{//Move/Swap Right
			if (cursorPosition.x < gridRows - 1) {
				if (swapMode == true)
				{
					SwapTile(sf::Vector2i(1,0));
				}
				else
				cursorPosition += sf::Vector2i(1, 0);
			}
			keydown = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{//Move/Swap Down
			if (cursorPosition.y < gridCols - 1)
			{
				if (swapMode == true)
				{
					SwapTile(sf::Vector2i(0, 1));
				}
				else
				cursorPosition += sf::Vector2i(0, 1);
			}
			keydown = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{//Move/Swap Up			
			if (cursorPosition.y > 0)
			{
				if (swapMode == true)
				{
					SwapTile(sf::Vector2i(0, -1));
				}
				else
				cursorPosition += sf::Vector2i(0, -1);
			}
			keydown = true;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{//When Space is pressed, changes modes to alter directional key function, and marks the currently selected tile as ready to be swapped.
			swapMode = true;
			tileToSwap = cursorPosition;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			return "mainMenu";
		}
	}
	else
	{
		keydown = false;
	}
	cursor.setPosition(grid[cursorPosition.x][cursorPosition.y].getPos());
	return "";
}

void GameScreen::draw(sf::RenderWindow & window)
{
	//Iterates through each tile...
	for (int i = 0; i < gridCols; i++)
	{
		for (int j = 0; j < gridRows; j++)
		{//...and calls its Draw method.
			grid[i][j].draw(window);
		}
	}
	//
	cursor.setTexture(cursorTex);
	window.draw(cursor);
}

GameScreen::~GameScreen()
{
}

void GameScreen::CheckMatch()
{

	int xCount=0,yCount=0, dirChecked=0;
	sf::Vector2i startTile=tileToSwap, currentTile=startTile, prevTile=startTile;
	
	while (dirChecked<4)
	{
		while (dirChecked==0)
		{//left
			currentTile += sf::Vector2i(-1, 0);
			if (compareTiles(grid[currentTile.x][currentTile.y], grid[prevTile.x][prevTile.y])&&currentTile.x>0)
			{
				xCount++;
				grid[currentTile.x][currentTile.y].checked = true;
			}
			else
			{
				dirChecked++;
				currentTile = startTile;
				prevTile = startTile;
			}
		}
		while (dirChecked == 1)
		{//up
			currentTile += sf::Vector2i(0,-1);
			if (compareTiles(grid[currentTile.x][currentTile.y], grid[prevTile.x][prevTile.y]) && currentTile.y>0)
			{
				yCount++;
				grid[currentTile.x][currentTile.y].checked = true;
			}
			else
			{
				dirChecked++;
				currentTile = startTile;
				prevTile = startTile;
			}
		}
		while (dirChecked == 2)
		{//right
			currentTile += sf::Vector2i(1, 0);
			if (compareTiles(grid[currentTile.x][currentTile.y], grid[prevTile.x][prevTile.y]) && currentTile.x<gridCols)
			{
				xCount++;
				grid[currentTile.x][currentTile.y].checked = true;
			}
			else
			{
				dirChecked++;
				currentTile = startTile;
				prevTile = startTile;
			}
		}
		while (dirChecked == 3)
		{//down
			currentTile += sf::Vector2i(0, 1);
			if (compareTiles(grid[currentTile.x][currentTile.y], grid[prevTile.x][prevTile.y]) && currentTile.y<gridRows)
			{
				yCount++;
				grid[currentTile.x][currentTile.y].checked = true;
			}
			else
			{
				dirChecked++;
				currentTile = startTile;
				prevTile = startTile;
			}
		}
	}

}

void GameScreen::SwapTile(sf::Vector2i dir)
{
	//Simple swap action, creates a temp variable and uses it to swap colour values.
	auto col = grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y].getCol(); //Setting up the temp...
	grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y].setCol(grid[tileToSwap.x][tileToSwap.y].getCol()); //Copies one tile's colour over the other's.
	grid[tileToSwap.x][tileToSwap.y].setCol(col); //Copies temp's colour over the first tile.
	//Now, to redraw the textures of both.
	grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y].updateTextures();
	grid[tileToSwap.x][tileToSwap.y].updateTextures();

	//Resets control mode back to Move Mode
	swapMode = false;
	CheckMatch();
}

bool GameScreen::compareTiles(Crystal & a, Crystal & b)
{//Checks if "type" value of both Crystals are identical.
	if (a.getCol() == b.getCol())
	{
		return true;
	}
	return false;
}

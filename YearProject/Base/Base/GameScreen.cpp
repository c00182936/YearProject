#include "GameScreen.h"

GameScreen::GameScreen(int gridHeight, int gridWidth) : gridCols(gridHeight), gridRows(gridWidth)
{
	//Need to make a 2D array or vector of vectors(?) to represent the grid.
	//vector< vector<object> >
	//Each entry is a Crystal object that has its Colour property.
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
			//It seems this [i][j] method of referring to a tile isn't going to work.
			//How do I 2D vector.
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// move left...
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
		{
			// move right...
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
		{
			// quit...
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
		{
			
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
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
	for (int i = 0; i < gridCols; i++)
	{
		for (int j = 0; j < gridRows; j++)
		{//Commenting this out for now until I can figure out how to refer to tile.
			grid[i][j].draw(window);
		}
	}
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
			currentTile += sf::Vector2i(0, -1);
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
{//VERY FUCKING JANKY
	//Crystal temp= grid[tileToSwap.x][tileToSwap.y];
	//grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y] =grid[tileToSwap.x][tileToSwap.y ];
	//grid[tileToSwap.x + dir.x][tileToSwap.x + dir.y] = temp;
	auto col = grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y].getCol();//a
	grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y].setCol(grid[tileToSwap.x][tileToSwap.y].getCol());//b=c
	grid[tileToSwap.x][tileToSwap.x].setCol(col);//c=a
	grid[tileToSwap.x + dir.x][tileToSwap.y + dir.y].updateTextures();
	grid[tileToSwap.x][tileToSwap.x].updateTextures();
	swapMode = false;
	//CheckMatch();
}

bool GameScreen::compareTiles(Crystal & a, Crystal & b)
{
	if (a.getCol() == b.getCol())
	{
		return true;
	}
	return false;
}

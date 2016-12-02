#include "GameScreen.h"

void GameScreen::resetChecked()
{
	for (size_t i = 0; i < gridCols; i++)
	{
		for (size_t u = 0; u < gridRows; u++)
		{
			grid.at(i).at(u).checked = false;
		}
	}
}
void GameScreen::MarkChecked()
{
	for (size_t i = 0; i < gridCols; i++)
	{
		for (size_t u = 0; u < gridRows; u++)
		{
			if (grid.at(i).at(u).checked == true)
			{
				grid.at(i).at(u).toRemove = true;
			}
		}
	}
}

GameScreen::GameScreen()
{
	gridCols = 10;
	gridRows = 10;
	std::vector<Crystal> temp;
	sf::Vector2f tempPos(40, 40);
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
		tempPos += sf::Vector2f(50, -gridRows * 50);
	}
}

GameScreen::GameScreen(int gridHeight=10, int gridWidth=10) : gridCols(gridHeight), gridRows(gridWidth)
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
		tempPos += sf::Vector2f(50, -gridRows*50);
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{//Move/Swap Up			
			resetChecked();
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
			if (grid.at(i).at(j).getCol() == Colour::null&&j>0)
			{
				//tileToSwap = sf::Vector2i(i, j);
				//SwapTileWithoutCheck(sf::Vector2i(0, -1));
			}
			grid[i][j].draw(window);
		}
	}
	//
	cursor.setTexture(cursorTex);
	window.draw(cursor);
}
//complete
void GameScreen::CheckMatch(sf::Vector2i check)
{
	int count = 0;
	//will increment when a match can't be found
	int dirChecked = 1;//1=left, 2=right, 3=up, 4=down, 5=fin
	//will check other directions until either a full match is found or all directions are checked
	sf::Vector2i currentTile=check; //will be iterated upon until no more matches and then set to check again

	//int xCount=0,yCount=0, dirChecked=0;
	//sf::Vector2i startTile=tileToSwap, currentTile=startTile, prevTile=startTile;
	//

	while (dirChecked<5)
	{
		assert(currentTile.x >= 0 && currentTile.x < grid.size());
		while (dirChecked==1)//left
		{
			//checks if the next tile to be iterated to is out of bounds
			if (currentTile.x - 1 < 0)
			{
				std::cout << "out of bounds" << std::endl;
				dirChecked++;
			}
			else if ((grid.at(currentTile.x).at(currentTile.y).getCol()== grid.at(currentTile.x-1).at(currentTile.y).getCol()))
			{//checks to the left of the current tile, and if true, moves the current tile in that direction
				currentTile.x -= 1;
				grid.at(currentTile.x).at(currentTile.y).checked = true;
				count++;
				std::cout << "Left"<< std::endl;
			}
			else if ((grid.at(currentTile.x).at(currentTile.y).getCol() != grid.at(currentTile.x - 1).at(currentTile.y).getCol()))
			{//if the two tiles don't match, set the currently selected tile to the origin and iterate direction
				dirChecked++;
				currentTile = check;
			}
			else
			{//if all else fails
				std::cout << "something went wrong" << std::endl;
				dirChecked++;
			}
		}
		while (dirChecked == 2)//right
		{
			//checks if the next tile to be iterated to is out of bounds
			if (currentTile.x + 1 >= gridCols)
			{
				std::cout << "out of bounds" << std::endl;
				dirChecked++;
			}
			else if ((grid.at(currentTile.x).at(currentTile.y).getCol() == grid.at(currentTile.x + 1).at(currentTile.y).getCol()))
			{
				currentTile.x += 1;
				grid.at(currentTile.x).at(currentTile.y).checked = true;
				count++;
				std::cout << "Right"<< std::endl;
			}
			else
			{
				dirChecked++;
				currentTile = check;
			}
		}
		if (count>=3)//ensures you don't have a multi shaped match
		{
			//dirChecked = 5;//if you have 4 or more in a row, you stop checking

			count = 0;//to not mess with the next set of checks
			grid.at(check.x).at(check.y).checked = true;
			
			currentTile = check;
			MarkChecked();
		}
		else
		{
			std::cout << "no X match" << std::endl;
			count = 0;//otherwise, you reset your count and try up/down
			currentTile = check;
			resetChecked();
		}
		while (dirChecked == 3)
		{
			//checks if the next tile to be iterated to is out of bounds
			if (currentTile.y - 1 <0)
			{
				std::cout << "out of bounds" << std::endl;
				dirChecked++;
			}
			else if ((grid.at(currentTile.x).at(currentTile.y).getCol() == grid.at(currentTile.x).at(currentTile.y-1).getCol()))
			{
				currentTile.y -= 1;
				grid.at(currentTile.x).at(currentTile.y).checked = true;
				count++;
				std::cout << "Up"<< std::endl;
			}
			else
			{
				dirChecked++;
				currentTile = check;
			}
		}
		while (dirChecked == 4)
		{
			//checks if the next tile to be iterated to is out of bounds
			if (currentTile.y + 1 >= gridRows)
			{
				std::cout << "out of bounds" << std::endl;
				dirChecked++;
			}
			else if ((grid.at(currentTile.x).at(currentTile.y).getCol() == grid.at(currentTile.x).at(currentTile.y + 1).getCol()))
			{
				currentTile.y += 1;
				grid.at(currentTile.x).at(currentTile.y).checked = true;
				count++;
				std::cout << "Down"<< std::endl;
			}
			else
			{
				dirChecked++;
				currentTile = check;
			}
		}
	}
	if (count < 3)
	{
		std::cout << "no Y match" << std::endl;
	}
	else if (count >=3)
	{
		grid.at(check.x).at(check.y).checked = true;
		MarkChecked();
		
	}
	resetChecked();
}
//complete
void GameScreen::SwapTile(sf::Vector2i dir)
{
	//Simple swap action, creates a temp variable and uses it to swap colour values.
	auto col = grid.at(tileToSwap.x + dir.x).at(tileToSwap.y + dir.y).getCol(); //Setting up the temp...

	grid.at(tileToSwap.x+dir.x).at(tileToSwap.y+dir.y).setCol(grid.at(tileToSwap.x).at(tileToSwap.y).getCol()); //Copies one tile's colour over the other's.

	grid.at(tileToSwap.x).at(tileToSwap.y).setCol(col); //Copies temp's colour over the first tile.

	//Now, to redraw the textures of both.

	grid.at(tileToSwap.x + dir.x).at(tileToSwap.y + dir.y).updateTextures();

	grid.at(tileToSwap.x).at(tileToSwap.y).updateTextures();

	//Resets control mode back to Move Mode
	
	CheckMatch(tileToSwap);
	CheckMatch(tileToSwap + dir);
	swapMode = false;
}
void GameScreen::SwapTileWithoutCheck(sf::Vector2i dir)
{
	//Simple swap action, creates a temp variable and uses it to swap colour values.
	auto col = grid.at(tileToSwap.x + dir.x).at(tileToSwap.y + dir.y).getCol(); //Setting up the temp...

	grid.at(tileToSwap.x + dir.x).at(tileToSwap.y + dir.y).setCol(grid.at(tileToSwap.x).at(tileToSwap.y).getCol()); //Copies one tile's colour over the other's.

	grid.at(tileToSwap.x).at(tileToSwap.y).setCol(col); //Copies temp's colour over the first tile.

														//Now, to redraw the textures of both.

	grid.at(tileToSwap.x + dir.x).at(tileToSwap.y + dir.y).updateTextures();

	grid.at(tileToSwap.x).at(tileToSwap.y).updateTextures();

	//Resets control mode back to Move Mode
}

bool GameScreen::compareTiles(Crystal & a, Crystal & b)
{//Checks if "type" value of both Crystals are identical.
	if (a.getCol() == b.getCol())
	{
		return true;
	}
	return false;
}

GameScreen::~GameScreen()
{
}

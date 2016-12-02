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

	p1 = Player();
	//hud = HudManager();
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

		//Added temporarily for the purpose of testing Ability Points.
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			{ p1.changeAP("Red", -100); }
			else
			{ p1.changeAP("Red", 20); }
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			{ p1.changeAP("Green", -100); }
			else
			{ p1.changeAP("Green", 20); }
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			{ p1.changeAP("Blue", -100); }
			else
			{ p1.changeAP("Blue", 20); }
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

	hud.Draw(window, p1.getAP("Red"), p1.getAP("Green"), p1.getAP("Blue"));
}

void GameScreen::CheckMatch(sf::Vector2i check)
{
	int count = 1;
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
			if (currentTile.x - 1 <= 0)
			{
				std::cout << "out of bounds" << std::endl;
				dirChecked++;
			}
			else if ((grid.at(currentTile.x).at(currentTile.y).getCol()== grid.at(currentTile.x-1).at(currentTile.y).getCol()))
			{
				currentTile.x -= 1;
				grid.at(currentTile.x).at(currentTile.y).checked = true;
				count++;
				std::cout << "Left"<< std::endl;
			}
			else
			{
				dirChecked++;
				currentTile = check;
			}
		}
		while (dirChecked == 2)//right
		{
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
		if (count>=4)//ensures you don't have a multi shaped match
		{
			dirChecked = 5;//if you have 4 or more in a row, you stop checking
		}
		else
		{
			count = 0;//otherwise, you reset your count and try up/down
			currentTile = check;
		}
		while (dirChecked == 3)
		{
			if (currentTile.y - 1 <=0)
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
		resetChecked();
	}
	else if (count > 3)
	{
		grid.at(currentTile.x).at(currentTile.y).checked = true;
	}
}

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

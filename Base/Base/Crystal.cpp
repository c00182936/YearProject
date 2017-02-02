#include "Crystal.h"


Crystal::Crystal()
{//By default, randomly selects a colour for the crystal.
	int ranType = rand() % 3;
	if (ranType == 0)
	{
		type = Colour::Red;
		tile.loadFromFile("Assets/Sprites/garnet.png");
	}
	else if (ranType == 1)
	{
		type = Colour::Green;
		tile.loadFromFile("Assets/Sprites/peridot.png");
	}
	else if (ranType == 2)
	{
		type = Colour::Blue;
		tile.loadFromFile("Assets/Sprites/sapphire.png");
	}
	//Other colours to be implemented later.
}

Crystal::Crystal(Colour colour)
{//Can be created with manual colour selection, perhaps for a fixed tutorial stage.
	type = colour;
}

Crystal::Crystal(sf::Vector2f pos):position(pos)
{
	int ranType = rand() % 3;
	if (ranType == 0)
	{
		type = Colour::Red;
		tile.loadFromFile("Assets/Sprites/garnet.png");
	}
	else if (ranType == 1)
	{
		type = Colour::Green;
		tile.loadFromFile("Assets/Sprites/peridot.png");
	}
	else if (ranType == 2)
	{
		type = Colour::Blue;
		tile.loadFromFile("Assets/Sprites/sapphire.png");
	}
	//Other colours to be implemented later.
	sprite.setPosition(pos);
	sprite.setScale(0.5, 0.5);
}

void Crystal::update()
{//find scaling factor, reduce on the axis that are listed
	if (toRemove == true)
	{
		if (animTime > 0)
		{

			animScale -= sf::Vector2f(scaleInc,scaleInc);
			animTime--;
		}
		if (animTime <= 0)
		{
			//sprite.setColor(sf::Color(255,255,255,50));
			//type = Colour::null;
			//toRemove = false;
			animScale = sf::Vector2f(0.5, 0.5);
		}

	}
	else if (toSwap == true)
	{
		if (animTime > 0)
		{
			animTime--;
			animScale -= animDir;
		}
		if (animTime <= 0)
		{
			//sprite.setColor(sf::Color(255,255,255,50));
			animScale = sf::Vector2f(0.5, 0.5);
			//toSwap = false;
			
		}

	}
}

void Crystal::draw(sf::RenderWindow &win)
{
	//Draw sprite based on "type" value (and its position in the vector?).
	//sprite.setTexture(tile);
	//if (toRemove == true)
	//{
	//	//sprite.setColor(sf::Color(255,255,255,50));
	//	type = Colour::null;
	//	toRemove = false;
	//}
	//if (type == Colour::null)
	//{
	//	sprite.setColor(sf::Color::Black);
	//}
	//else
	//{
	//	sprite.setColor(sf::Color::White);
	//}
	//win.draw(sprite);
}

sf::Vector2f & Crystal::getPos()
{
	// TODO: insert return statement here
	return position;
}



void Crystal::updateTextures()
{
	//if (type == Colour::Red)
	//{
	//	//sprite.setColor(sf::Color::White);
	//	tile.loadFromFile("Assets/Sprites/garnet.png");
	//}
	//else if (type == Colour::Green)
	//{
	//	//sprite.setColor(sf::Color::White);
	//	tile.loadFromFile("Assets/Sprites/peridot.png");
	//}
	//else if (type == Colour::Blue)
	//{
	//	//sprite.setColor(sf::Color::White);
	//	tile.loadFromFile("Assets/Sprites/sapphire.png");
	//}
	if (type == Colour::null)
	{
		sprite.setColor(sf::Color(255, 255, 255, 0));
	}
}
void Crystal::setRemoveAnim()
{
	toRemove = true;
	animTime = removeTiming;
	scaleInc = 0.5 / animTime;
}

void Crystal::setSwapAnim(sf::Vector2i dir)
{
	animDir.x = dir.x;
	animDir.y = dir.y;
	toSwap = true;
	animTime = swapTiming;
	scaleInc = 0.5 / animTime;
	animDir.x*=scaleInc;
	animDir.y *= scaleInc;
}

Crystal::~Crystal()
{

}
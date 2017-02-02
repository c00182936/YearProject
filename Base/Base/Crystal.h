#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include"Colour.h"
class Crystal
{
private:

	Colour type; //Stores the value of individual colour.
	sf::Texture tile;
	sf::Sprite sprite;
	sf::Vector2f position;
	int removeTiming = 20;
	int swapTiming = 10;
	float scaleInc=0;
public:
	int animTime;
	sf::Vector2f animDir;//[1]shrink on the x, [1] shrink on the y;
	sf::Vector2f animScale=sf::Vector2f(1,1);
	void setRemoveAnim();
	void setSwapAnim(sf::Vector2i dir);
	
	Crystal();
	Crystal(Colour colour);
	Crystal(sf::Vector2f pos);
	void update();
	void draw(sf::RenderWindow &win);
	sf::Vector2f &getPos();
	Colour &getCol() { return type; };
	void setCol(Colour c) { type = c; }
	void updateTextures();
	bool checked=false;
	bool toRemove=false;
	bool toSwap=false;
	bool removeAnim = false;

	~Crystal();
};

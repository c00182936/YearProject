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
	int removeTiming = 30;
public:
	int removeAnim = 30;
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
	~Crystal();
};

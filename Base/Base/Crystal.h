#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Crystal
{
private:
	enum class Colour 
	{
		Red, Green, Blue,
		Cyan, Magenta, Yellow,
		Black, White, Rainbow
	};
	Colour type; //Stores the value of individual colour.
	sf::Texture tile;
	sf::Sprite sprite;
	sf::Vector2f position;
	
public:
	Crystal();
	Crystal(Colour colour);
	Crystal(sf::Vector2f pos);
	void update(sf::RenderWindow &win);
	void draw(sf::RenderWindow &win);
	sf::Vector2f &getPos();
	Colour &getCol() { return type; };
	void setCol(Colour c) { type = c; }
	void updateTextures();
	bool checked;
	~Crystal();
};

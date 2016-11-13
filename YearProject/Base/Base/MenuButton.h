#pragma once
#include<SFML\Graphics.hpp>
class MenuButton
{
private:
	sf::Texture tex;
	sf::Sprite sprite;
	bool selected;
	bool pressed;
	sf::FloatRect rect;
	std::string action;
	sf::Font font;
	sf::Text text;
public:
	MenuButton();
	MenuButton(std::string title, std::string spriteLocation, sf::Vector2f pos );
	bool checkOver(sf::Vector2f &mousePos);//checks if the mouse is over the rect
	bool * getSelected();
	const std::string* getAction();
	sf::Sprite & getSprite();
	void draw(sf::RenderWindow &win);
	//need something to select, manager to iterate with the mouse and keyboard.
	~MenuButton();
};


#include "MenuButton.h"
#include <iostream>


MenuButton::MenuButton()
{
}

MenuButton::MenuButton(std::string title, std::string spriteLocation, sf::Vector2f pos):action(title)
{
	if (!tex.loadFromFile(spriteLocation))
	{
		std::cout << "error loading button sprite" << std::endl;
	}
	if (!font.loadFromFile("Assets/Fonts/Score Board St.ttf"));
	{
		std::cout << "error loading font" << std::endl;
	}
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.x,pos.y));
	rect = sf::FloatRect(pos, sf::Vector2f(tex.getSize().x, tex.getSize().y));
	text.setFont(font);
	text.setString(action);
	text.setPosition(pos + sf::Vector2f(25, 25));
}

bool MenuButton::checkOver(sf::Vector2f &mousePos)
{
	bool y;
//	std::cout << rect.left << " " << rect.top << " " << rect.height+rect.top << " " << rect.width + rect.left << std::endl;
	y = rect.contains(mousePos.x, mousePos.y);
	return y;
}

bool * MenuButton::getSelected()
{
	return &selected;
}

const std::string * MenuButton::getAction()
{
	return &action;
}

sf::Sprite & MenuButton::getSprite()
{
	// TODO: insert return statement here
	return sprite;
}

void MenuButton::draw(sf::RenderWindow & win)
{
	sprite.setTexture(tex);
	text.setFont(font);
	win.draw(sprite);
	win.draw(text);
}


MenuButton::~MenuButton()
{
}

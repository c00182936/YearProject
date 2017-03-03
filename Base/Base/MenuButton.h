#pragma once
#include<SFML\Graphics.hpp>
class MenuButton
{
private:
	/// the sprite and texture of the button
	sf::Texture tex;
	sf::Sprite sprite;

	///booleans for selected and pressed states
	bool selected;
	bool pressed;

	/// the collision rectangle
	sf::FloatRect rect;

	/// the action returned when the button is pressed
	std::string action;

	//the font to display the text, and the text for the font to display
	sf::Font font;
	sf::Text text;
public:
	//////////////////////////////////
	//\brief default constructor
	//
	//\param none
	/////////////////////////////////
	MenuButton();
	//////////////////////////////////
	//\brief used constructor
	//
	//\param title of the button, the location of the sprite, the position of the button
	/////////////////////////////////
	MenuButton(std::string title, std::string spriteLocation, sf::Vector2f pos );
	//////////////////////////////////
	//\briefchecks if the mouse is over the rect
	//
	//\param position of the mouse
	/////////////////////////////////
	bool checkOver(sf::Vector2f &mousePos);
	//////////////////////////////////
	//\brief checks if the button is selected
	//
	//\param none
	/////////////////////////////////
	bool * getSelected();

	//////////////////////////////////
	//\brief returns the action of the button
	//
	//\param none
	/////////////////////////////////
	const std::string* getAction();
	//////////////////////////////////
	//\brief unused method to get the sprite used
	//
	//\param
	/////////////////////////////////
	sf::Sprite & getSprite();
	//////////////////////////////////
	//\brief draw method
	//
	//\param reference to render window
	/////////////////////////////////
	void draw(sf::RenderWindow &win);
	//////////////////////////////////
	//\brief destructor
	//
	//\param none
	/////////////////////////////////
	~MenuButton();
};


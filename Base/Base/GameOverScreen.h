#pragma once
#include<SFML\Graphics.hpp>
#include<string>


class GameOverScreen
{
private:
	///sprite for the background
	sf::Sprite spr;
	///texture for the background
	sf::Texture tex;
	///font for the message
	sf::Font font;
	///the message
	sf::Text message;
	///the string the message is set to
	std::string s;
public:
	//////////////////////////////////
	//\brief default constructor
	//
	//\param none
	/////////////////////////////////
	GameOverScreen();
	//////////////////////////////////
	//\brief used constructor
	//
	//\param the player score
	/////////////////////////////////
	GameOverScreen(int score);
	/// the player score
	int score;
	//////////////////////////////////
	//\brief the draw method
	//
	//\param a render window
	/////////////////////////////////
	void Draw(sf::RenderWindow &win);
	//////////////////////////////////
	//\brief the update loop
	//
	//\param returns a string for messages
	/////////////////////////////////
	std::string update();



	~GameOverScreen();
};


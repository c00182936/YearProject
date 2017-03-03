#include "GameOverScreen.h"
#include <iostream>
////////////////////////
// default constructor
////////////////////////

GameOverScreen::GameOverScreen()
{
	s = "default";
}
//////////////////////////
// constructor, sets score to a string to display
/////////////////////////
GameOverScreen::GameOverScreen(int score)
{
	s = "Thanks for playing! your score: " + std::to_string(score);
	tex.loadFromFile("Assets/Sprites/screen.png");
	spr.setTexture(tex);
	font.loadFromFile("Assets/Fonts/score board st.ttf");
	message.setFont(font);
	message.setFillColor(sf::Color::Yellow);
	message.setPosition(sf::Vector2f(10, 300));


}
//////////////////////
//draws the update loop
//////////////////////
void GameOverScreen::Draw(sf::RenderWindow & win)
{
	spr.setTexture(tex);
	message.setFont(font);
	message.setString(s);
	win.draw(spr);
	win.draw(message);
}
/////////////////////
//update loop
/////////////////////
std::string GameOverScreen::update()
{
	return std::string();
}

////////////////////
// destructor
////////////////////
GameOverScreen::~GameOverScreen()
{
}

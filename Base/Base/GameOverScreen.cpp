#include "GameOverScreen.h"
#include <iostream>


GameOverScreen::GameOverScreen()
{
	s = "default";
}

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

void GameOverScreen::Draw(sf::RenderWindow & win)
{
	spr.setTexture(tex);
	message.setFont(font);
	message.setString(s);
	win.draw(spr);
	win.draw(message);
}

std::string GameOverScreen::update()
{
	return std::string();
}


GameOverScreen::~GameOverScreen()
{
}

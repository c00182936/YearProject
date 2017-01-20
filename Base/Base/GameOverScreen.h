#pragma once
#include<SFML\Graphics.hpp>
#include<string>


class GameOverScreen
{
private:
	sf::Sprite spr;
	sf::Texture tex;
	sf::Font font;
	sf::Text message;
	std::string s;
public:
	GameOverScreen();
	GameOverScreen(int score);
	int score;
	void Draw(sf::RenderWindow &win);
	std::string update();



	~GameOverScreen();
};


#pragma once

#include <SFML\Graphics.hpp>
#include "Player.h"
class HudManager
{
public:
	HudManager();

	void Draw(sf::RenderWindow &win, Player p1);

	~HudManager();
private:
	int point;
	sf::VertexArray a;

	sf::Font font;

	sf::Vector2f rBarPos;
	sf::Vector2f gBarPos;
	sf::Vector2f bBarPos;
	//const sf::Vector2i BAR_OFFSET = sf::Vector2i(5,5);

	sf::Texture apBarBack;
	sf::Sprite rGauge, gGauge, bGauge;
};


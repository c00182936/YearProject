#pragma once
#include <SFML\Graphics.hpp>
class HudManager
{
public:
	HudManager();
	void Draw(sf::RenderWindow &win);
	~HudManager();
private:
	int point;
	sf::VertexArray a;
};


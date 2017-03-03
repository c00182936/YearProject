#pragma once

#include <SFML\Graphics.hpp>
#include "Player.h"
class HudManager
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Default Constructor
	///
	/// \param None
	////////////////////////////////////////////////////////////
	HudManager();

	////////////////////////////////////////////////////////////
	/// \brief Draw and fill the bars, and display game elements.
	///
	/// \param Window to draw on, player's stats are referenced.
	////////////////////////////////////////////////////////////
	void Draw(sf::RenderWindow & win, Player player);

	////////////////////////////////////////////////////////////
	/// \brief Destructor Function
	///
	/// \param None
	////////////////////////////////////////////////////////////
	~HudManager();

private:
	///Font used to display time/combo/score.
	sf::Font font;

	///Positions at which each bar should be drawn.
	sf::Vector2f rBarPos;
	sf::Vector2f gBarPos;
	sf::Vector2f bBarPos;

	///Black bar texture with multiple segments.
	sf::Texture apBarBack;

	///Rectangles drawn over the black bars to fill.
	sf::Sprite rGauge, gGauge, bGauge;
};


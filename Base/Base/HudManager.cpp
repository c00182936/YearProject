#include "HudManager.h"

HudManager::HudManager()
{
	rBarPos = sf::Vector2f(650, 50);
	gBarPos = sf::Vector2f(650, 150);
	bBarPos = sf::Vector2f(650, 250);

	if (!apBarBack.loadFromFile("Assets/Sprites/ap_bar_back.png"))
	{

	}

	rGauge.setPosition(rBarPos);
	gGauge.setPosition(gBarPos);
	bGauge.setPosition(bBarPos);
}

void HudManager::Draw(sf::RenderWindow & win, int r, int g, int b)
{
	rGauge.setTexture(apBarBack);
	gGauge.setTexture(apBarBack);
	bGauge.setTexture(apBarBack);

	win.draw(rGauge);
	win.draw(gGauge);
	win.draw(bGauge);

	int rVal = 0;
	if (r == 300) 
	{ rVal = 100; }
	else 
	{ rVal = r % 100; }
	int rBars = r / 100;

	int gVal = 0;
	if (g == 300)
	{ gVal = 100; }
	else
	{ gVal = g % 100; }
	int gBars = g / 100;

	int bVal = 0;
	if (b == 300)
	{ bVal = 100; }
	else
	{ bVal = b % 100; }
	int bBars = b / 100;

	//Get values from Player class.
	sf::RectangleShape rFill(sf::Vector2f(rVal * 4.9, 42));
	rFill.setPosition(rBarPos + sf::Vector2f(5, 5));
	rFill.setFillColor(sf::Color(255, 0, 0));
	sf::RectangleShape gFill(sf::Vector2f(gVal * 4.9, 42));
	gFill.setPosition(gBarPos + sf::Vector2f(5, 5));
	gFill.setFillColor(sf::Color(0, 255, 0));
	sf::RectangleShape bFill(sf::Vector2f(bVal * 4.9, 42));
	bFill.setPosition(bBarPos + sf::Vector2f(5, 5));
	bFill.setFillColor(sf::Color(0, 0, 255));

	win.draw(rFill);
	win.draw(gFill);
	win.draw(bFill);

	if (rBars >= 1)
	{
		//Draw first bar.
		sf::RectangleShape rBar1(sf::Vector2f(160, 20));
		rBar1.setPosition(rBarPos + sf::Vector2f(5, 52));
		rBar1.setFillColor(sf::Color(255, 0, 0));
		win.draw(rBar1);

		if (rBars >= 2)
		{
			//Draw second bar.
			sf::RectangleShape rBar2(sf::Vector2f(160, 20));
			rBar2.setPosition(rBarPos + sf::Vector2f(170, 52));
			rBar2.setFillColor(sf::Color(255, 0, 0));
			win.draw(rBar2);

			if (rBars >= 3)
			{
				//Draw third bar.
				sf::RectangleShape rBar3(sf::Vector2f(160, 20));
				rBar3.setPosition(rBarPos + sf::Vector2f(335, 52));
				rBar3.setFillColor(sf::Color(255, 0, 0));
				win.draw(rBar3);
			}
		}
	}

	if (gBars >= 1)
	{
		//Draw first bar.
		sf::RectangleShape gBar1(sf::Vector2f(160, 20));
		gBar1.setPosition(gBarPos + sf::Vector2f(5, 52));
		gBar1.setFillColor(sf::Color(0, 255, 0));
		win.draw(gBar1);

		if (gBars >= 2)
		{
			//Draw second bar.
			sf::RectangleShape gBar2(sf::Vector2f(160, 20));
			gBar2.setPosition(gBarPos + sf::Vector2f(170, 52));
			gBar2.setFillColor(sf::Color(0, 255, 0));
			win.draw(gBar2);

			if (gBars >= 3)
			{
				//Draw third bar.
				sf::RectangleShape gBar3(sf::Vector2f(160, 20));
				gBar3.setPosition(gBarPos + sf::Vector2f(335, 52));
				gBar3.setFillColor(sf::Color(0, 255, 0));
				win.draw(gBar3);
			}
		}
	}

	if (bBars >= 1)
	{
		//Draw first bar.
		sf::RectangleShape bBar1(sf::Vector2f(160, 20));
		bBar1.setPosition(bBarPos + sf::Vector2f(5, 52));
		bBar1.setFillColor(sf::Color(0, 0, 255));
		win.draw(bBar1);

		if (bBars >= 2)
		{
			//Draw second bar.
			sf::RectangleShape bBar2(sf::Vector2f(160, 20));
			bBar2.setPosition(bBarPos + sf::Vector2f(170, 52));
			bBar2.setFillColor(sf::Color(0, 0, 255));
			win.draw(bBar2);

			if (bBars >= 3)
			{
				//Draw third bar.
				sf::RectangleShape bBar3(sf::Vector2f(160, 20));
				bBar3.setPosition(bBarPos + sf::Vector2f(335, 52));
				bBar3.setFillColor(sf::Color(0, 0, 255));
				win.draw(bBar3);
			}
		}
	}
}


HudManager::~HudManager()
{
}

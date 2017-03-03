#include "HudManager.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// Constructor 
//////////////////////////////////////////////////////////////////////////////////
HudManager::HudManager()
{
	rBarPos = sf::Vector2f(650, 50);
	gBarPos = sf::Vector2f(650, 150);
	bBarPos = sf::Vector2f(650, 250);

	if (!apBarBack.loadFromFile("Assets/Sprites/ap_bar_back.png"))
	{

	}
	if (!font.loadFromFile("Assets/Fonts/Roboto-Regular.ttf")) {

	}


	rGauge.setPosition(rBarPos);
	gGauge.setPosition(gBarPos);
	bGauge.setPosition(bBarPos);
}

//////////////////////////////////////////////////////////////////////////////////
// Draw and fill the bars, and display game elements.
//////////////////////////////////////////////////////////////////////////////////
void HudManager::Draw(sf::RenderWindow & win, Player player)
{
	sf::Time gTime = player.getGameTime();
	sf::Time cTime = player.getComboTime();
	float cLevel = player.getComboLV();
	int pts = player.getScore();
	int r = player.getAP("Red");
	int g = player.getAP("Green");
	int b = player.getAP("Blue");

	//Draw game timers.
	int seconds = (int)gTime.asSeconds() % 60;
	int minutes = gTime.asSeconds() / 60;

	//Divider stuff so that it shows for example "4:09" rather than the weird-looking "4:9".
	std::string divider;
	if (seconds < 10) {
		divider = ":0";
	}
	else {
		divider = ":";
	}

	std::string gTimeDisplay;
	gTimeDisplay.append(std::to_string(minutes));
	gTimeDisplay.append(divider);
	gTimeDisplay.append(std::to_string(seconds));

	//Replace this with text drawing in the game window.
	//std::cout << gTimeDisplay << std::endl;

	sf::Text gTimeText;
	gTimeText.setFont(font);
	gTimeText.setString(gTimeDisplay);
	gTimeText.setCharacterSize(40);
	gTimeText.setOutlineColor(sf::Color::Black);
	gTimeText.setOutlineThickness(1);
	if (minutes == 0)
	{
		gTimeText.setFillColor(sf::Color::Red);
	}
	gTimeText.setPosition(sf::Vector2f(650, 350));

	std::string cLevelDisplay;
	cLevelDisplay.append(std::to_string(cLevel));
	cLevelDisplay.append("x");

	sf::Text cLevelText;
	cLevelText.setFont(font);
	cLevelText.setString(cLevelDisplay);
	cLevelText.setCharacterSize(24);

	if (player.getFeverLV())
	{//If the combo counter is frozen by Fever Mode, draw in red to signify this.
		cLevelText.setFillColor(sf::Color(255, 0, 0, 255));
	}
	else if (cTime.asSeconds() < 5)
	{//Combo counter begins to fade when combo time is running out.
		cLevelText.setFillColor(sf::Color(0, 0, 255, 127));
	}
	else
	{//Otherwise draws as normal.
		cLevelText.setFillColor(sf::Color(0, 0, 255, 255));
	}

	cLevelText.setPosition(sf::Vector2f(750, 350));

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString(std::to_string(pts));
	scoreText.setCharacterSize(24);
	scoreText.setPosition(sf::Vector2f(850, 400));

	win.draw(gTimeText);
	if (cLevel > 1)
	{
		win.draw(cLevelText);
	}
	win.draw(scoreText);

	//Draw Ability gauges.

	rGauge.setTexture(apBarBack);
	gGauge.setTexture(apBarBack);
	bGauge.setTexture(apBarBack);


	//Drawing the backs of the bars.

	win.draw(rGauge);
	win.draw(gGauge);
	win.draw(bGauge);


	//Getting the values of the fills.

	int rVal = 0;
	if (r == 300)
	{
		rVal = 100;
	}
	else
	{
		rVal = r % 100;
	}
	int rBars = r / 100;

	int gVal = 0;
	if (g == 300)
	{
		gVal = 100;
	}
	else
	{
		gVal = g % 100;
	}
	int gBars = g / 100;

	int bVal = 0;
	if (b == 300)
	{
		bVal = 100;
	}
	else
	{
		bVal = b % 100;
	}
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


	//Drawing the filled bars below, to indicate stored charges.

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

//////////////////////////////////////////////////////////////////////////////////
// Destructor 
//////////////////////////////////////////////////////////////////////////////////
HudManager::~HudManager()
{
}

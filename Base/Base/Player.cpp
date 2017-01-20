#include "Player.h"

Player::Player()
{//By default, game time starts at 300,000ms, or five minutes.
	gameTime = sf::seconds(300);
	comboTime = sf::seconds(0);
	rCharge = 0; gCharge = 0; bCharge = 0;
	score = 0;
	comboLevel = 1;
}

Player::Player(sf::Time gTime) : gameTime(gTime)
{

}

void Player::changeScore(int length, std::string colour)
{
	//Calculating point gain.
	int ptsGain = 0;
	for (int i = 1; i <= length; i++)
	{
		ptsGain += i * 100;
	}
	int apGain = ptsGain * 0.1;
	ptsGain *= comboLevel;

	//Increases total score.
	score += ptsGain;

	//Increases ability charge and combo counter if applicable.
	if (colour == "Red" && ptsGain > 0)
	{
		rCharge += apGain;
		comboLevel += 1.5;
	}
	else if (colour == "Green" && ptsGain > 0)
	{
		gCharge += apGain;
		comboLevel += 1;
	}
	else if (colour == "Blue" && ptsGain > 0)
	{
		bCharge += apGain;
		comboLevel += 1;
	}
	else
	{
		comboLevel += 1;
	}
	//Reset combo timer.
	comboTime = sf::seconds(10);
}
void Player::changeScore(int length, Colour colour)
{
	//Calculating point gain.
	int ptsGain = 0;
	for (int i = 1; i <= length; i++)
	{
		if (length > 2)
		{
			ptsGain += i * 100;
		}
	}
	int apGain = ptsGain * 0.025;
	ptsGain *= comboLevel;

	//Increases total score.
	score += ptsGain;

	//Increases ability charge and combo counter if applicable.
	if (ptsGain > 0)
	{
		if (colour == Colour::Red)
		{
			rCharge += apGain; 
			if (rCharge > 300)
			{
				rCharge = 300;
			}
			comboLevel += 1.5;
			comboTime = sf::seconds(10);
		}
		else if (colour == Colour::Green)
		{
			gCharge += apGain;
			if (gCharge > 300)
			{
				gCharge = 300;
			}
			comboLevel += 1;
			comboTime = sf::seconds(10);
		}
		else if (colour == Colour::Blue)
		{
			bCharge += apGain;
			if (bCharge > 300)
			{
				bCharge = 300;
			}
			comboLevel += 1;
			comboTime = sf::seconds(10);
		}
		else
		{
			comboLevel += 1;
		}
	}
}
void Player::changeAP(std::string colour, int apGain)
{//Temporary method for testing purposes, might be removed later. 
	//Added so that AP can be increased/decreased without messing with the score.
	if (colour == "Red")
	{ 
		rCharge += apGain; 
		if (rCharge > 300)
		{ rCharge = 300; }
		else if (rCharge < 0)
		{ rCharge = 0; }
	}
	else if (colour == "Green")
	{ 
		gCharge += apGain; 
		if (gCharge > 300)
		{ gCharge = 300; }
		else if (gCharge < 0)
		{ gCharge = 0; }
	}
	else if (colour == "Blue")
	{ 
		bCharge += apGain; 
		if (bCharge > 300)
		{ bCharge = 300; }
		else if (bCharge < 0)
		{ bCharge = 0; }
	}
}
void Player::changeAP(Colour colour, int apGain)
{//Temporary method for testing purposes, might be removed later. 
 //Added so that AP can be increased/decreased without messing with the score.
	if (colour == Colour::Red)
	{
		rCharge += apGain;
		if (rCharge > 300)
		{
			rCharge = 300;
		}
		else if (rCharge < 0)
		{
			rCharge = 0;
		}
	}
	else if (colour == Colour::Green)
	{
		gCharge += apGain;
		if (gCharge > 300)
		{
			gCharge = 300;
		}
		else if (gCharge < 0)
		{
			gCharge = 0;
		}
	}
	else if (colour == Colour::Blue)
	{
		bCharge += apGain;
		if (bCharge > 300)
		{
			bCharge = 300;
		}
		else if (bCharge < 0)
		{
			bCharge = 0;
		}
	}
}

std::string Player::update(sf::Time interval)
{
	std::string message = "";
	gameTime -= interval;
	if (comboTime.asSeconds() > 0)
	{
		comboTime -= interval;
	}
	if (comboTime - interval < sf::seconds(0))
	{//When time runs out, reset combo.
		comboTime = sf::seconds(0);
		comboLevel = 1;
	}
	if (gameTime.asSeconds() < 0)
	{
		message = "gameOver";
	}
	//gameTime--;
	//comboTime--;
	return message;
}

int Player::getScore()
{
	return score;
}
int Player::getAP(std::string colour)
{
	if (colour == "Red")
	{
		return rCharge;
	}
	else if (colour == "Green")
	{
		return gCharge;
	}
	else if (colour == "Blue")
	{
		return bCharge;
	}
	else
	{
		//Wrong colour input.
	}
}
float Player::getComboLV()
{
	return comboLevel;
}
sf::Time Player::getComboTime()
{
	return comboTime;
}
sf::Time Player::getGameTime()
{
	return gameTime;
}
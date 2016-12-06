#include "Player.h"

Player::Player()
{//By default, game time starts at 300,000ms, or five minutes.
	gameTime = 300000;
	rCharge = 0; gCharge = 0; bCharge = 0;
}

Player::Player(int gTime) : gameTime(gTime)
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
	int apGain = ptsGain * 0.01;
	ptsGain *= comboLevel;

	//Increases total score.
	score += ptsGain;

	//Increases ability charge and combo counter if applicable.
	if (colour == "Red")
	{
		rCharge += apGain;
		comboLevel += 1.5;
	}
	else if (colour == "Green")
	{
		gCharge += apGain;
		comboLevel += 1;
	}
	else if (colour == "Blue")
	{
		bCharge += apGain;
		comboLevel += 1;
	}
	else
	{
		comboLevel += 1;
	}
	//Reset combo timer.
	comboTime = 10000;
}
void Player::changeScore(int length, Colour colour)
{
	//Calculating point gain.
	int ptsGain = 0;
	for (int i = 1; i <= length; i++)
	{
		ptsGain += i * 100;
	}
	int apGain = ptsGain * 0.01;
	ptsGain *= comboLevel;

	//Increases total score.
	score += ptsGain;

	//Increases ability charge and combo counter if applicable.
	if (colour ==Colour::Red)
	{
		rCharge += apGain;
		comboLevel += 1.5;
	}
	else if (colour == Colour::Green)
	{
		gCharge += apGain;
		comboLevel += 1;
	}
	else if (colour == Colour::Blue)
	{
		bCharge += apGain;
		comboLevel += 1;
	}
	else
	{
		comboLevel += 1;
	}
	//Reset combo timer.
	comboTime = 10000;
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

void Player::update()
{
	gameTime--;
	//comboTime--;
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
int Player::getComboTime()
{
	return comboTime;
}
int Player::getGameTime()
{
	return gameTime;
}
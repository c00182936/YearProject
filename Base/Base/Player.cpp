#include "Player.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////////////////
Player::Player()
{//By default, game time starts at 300,000ms, or five minutes.
	gameTime = sf::seconds(300);
	comboTime = sf::seconds(0);
	feverTime = sf::seconds(0);
	rCharge = 0; gCharge = 0; bCharge = 0;
	score = 0;
	prevScore = 0;
	comboLevel = 1;
	prevComboLevel = 1;
	reverseAvailable = false;
}

//////////////////////////////////////////////////////////////////////////////////
// Modified constructor.
//////////////////////////////////////////////////////////////////////////////////
Player::Player(sf::Time gTime) : gameTime(gTime)
{
	gameTime = sf::seconds(300);
	comboTime = sf::seconds(0);
	feverTime = sf::seconds(0);
	rCharge = 0; gCharge = 0; bCharge = 0;
	score = 0;
	comboLevel = 1;
}

//////////////////////////////////////////////////////////////////////////////////
// Used to add points to the player's score.
//////////////////////////////////////////////////////////////////////////////////
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
			if (feverEX)
			{
				comboLevel += 4.5;
			}
			else
			{
				comboLevel += 1.5;
			}
			comboTime = sf::seconds(10);
		}
		else if (colour == Colour::Green)
		{
			gCharge += apGain;
			if (gCharge > 300)
			{
				gCharge = 300;
			}
			if (feverEX)
			{
				comboLevel += 3;
			}
			else
			{
				comboLevel += 1;
			}
			comboTime = sf::seconds(10);
		}
		else if (colour == Colour::Blue)
		{
			bCharge += apGain;
			if (bCharge > 300)
			{
				bCharge = 300;
			}
			if (feverEX)
			{
				comboLevel += 3;
			}
			else
			{
				comboLevel += 1;
			}
			comboTime = sf::seconds(10);
		}
		else
		{
			if (feverEX)
			{
				comboLevel += 3;
			}
			else
			{
				comboLevel += 1;
			}
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////
// Alters the current ability point value for the specified ability.
//////////////////////////////////////////////////////////////////////////////////
void Player::changeAP(std::string colour, int apGain)
{//Temporary method for testing purposes, might be removed later. 
 //Added so that AP can be increased/decreased without messing with the score.
	if (colour == "Red")
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
	else if (colour == "Green")
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
	else if (colour == "Blue")
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

//////////////////////////////////////////////////////////////////////////////////
// Updates all in-game timers.
//////////////////////////////////////////////////////////////////////////////////
std::string Player::update(sf::Time interval)
{
	std::string message = "";
	gameTime -= interval;
	if (feverTime.asSeconds() > 0) 
	{
		feverTime -= interval;
	}
	if (comboTime.asSeconds() > 0 && feverTime.asSeconds() <= 0)
	{
		comboTime -= interval;
	}
	if (comboTime - interval < sf::seconds(0))
	{//When time runs out, reset combo.
		comboTime = sf::seconds(0);
		comboLevel = 1;
	}
	if (feverTime.asSeconds() <= 0)
	{
		feverEX = false;
	}
	if (gameTime.asSeconds() < 0)
	{
		message = "gameOver";
	}
	//gameTime--;
	//comboTime--;
	return message;
}

//////////////////////////////////////////////////////////////////////////////////
// Consumes red ability points to boost the combo.
//////////////////////////////////////////////////////////////////////////////////
void Player::fever(bool ex)
{
	if (feverTime.asSeconds() <= 0)
	{//Only works if Fever isn't already active.
		if (ex) {//If using the advanced form of Fever.
			if (getAP("Red") == 300) {//Requires a full three bars. Costs all AP, sets Fever timer and activates EX bool.
				//For a short time, prevents combo timer from decreasing and triples combo counter increment rate.
				changeAP("Red", -300);
				feverTime = sf::seconds(5);
				feverEX = true;
			}
		}
		else {//If using the normal form.
			if (getAP("Red") >= 100) {//Requires one bar. Costs one bar and sets Fever timer.
				//For a short time, prevents the combo timer from decreasing to give a little extra time to continue the combo.
				changeAP("Red", -100);
				feverTime = sf::seconds(5);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Consumes blue ability points to undo the last move.
//////////////////////////////////////////////////////////////////////////////////
bool Player::reverse(bool ex)
{
	std::cout << "in reverse" << std::endl;
	if (reverseAvailable) {
		if (ex) {
			if (getAP("Blue") == 300) {//Requires a full three bars. Costs all AP, resets to previous state, not including score and combo level.
				changeAP("Blue", -300);
				reverseAvailable = false;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (getAP("Blue") >= 100) {//Requires one bar. Costs one bar, resets to previous state, including score and combo level.
				changeAP("Blue", -100);
				score = prevScore;
				comboLevel = prevComboLevel;
				reverseAvailable = false;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Consumes green ability points to add game time.
//////////////////////////////////////////////////////////////////////////////////
void Player::timeBonus(bool ex) {
	if (ex) {
		if (getAP("Green") == 300) {//Requires a full three bars. Costs all AP, greatly increases time remaining.
			changeAP("Green", -300);
			gameTime = sf::seconds(gameTime.asSeconds() + 30);
		}
	}
	else {
		if (getAP("Green") >= 100) {//Requires one bar. Costs one bar, slightly increases time remaining.
			changeAP("Green", -100);
			gameTime = sf::seconds(gameTime.asSeconds() + 5);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Before each move, sets "previous" values equal to current ones.
//////////////////////////////////////////////////////////////////////////////////
void Player::updatePrevious() {
	if (!reverseAvailable) {
		reverseAvailable = true;
	}
	prevScore = score;
	prevComboLevel = comboLevel;
}

//////////////////////////////////////////////////////////////////////////////////
// Returns the player's current score.
//////////////////////////////////////////////////////////////////////////////////
int Player::getScore()
{
	return score;
}

//////////////////////////////////////////////////////////////////////////////////
// Returns ability points for the specified ability.
//////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////
// Returns the current combo level.
//////////////////////////////////////////////////////////////////////////////////
float Player::getComboLV()
{
	return comboLevel;
}

//////////////////////////////////////////////////////////////////////////////////
// Returns number of seconds until combo ends.
//////////////////////////////////////////////////////////////////////////////////
sf::Time Player::getComboTime()
{
	return comboTime;
}

//////////////////////////////////////////////////////////////////////////////////
// Returns number of seconds until game ends.
//////////////////////////////////////////////////////////////////////////////////
sf::Time Player::getGameTime()
{
	return gameTime;
}

//////////////////////////////////////////////////////////////////////////////////
// Returns whether or not Fever is active in any form.
//////////////////////////////////////////////////////////////////////////////////
bool Player::getFeverLV()
{
	return (feverTime.asSeconds() > 0);
}

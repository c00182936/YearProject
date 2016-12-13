#pragma once

#include <string>

#include <SFML/System/Time.hpp>

#include "Colour.h"
class Player
{
private:
	//const int COMBO_TIME_MAX = 10000;
	//const float ABILITY_POINT_MULTIPLIER = 0.01f;

	int score;

	sf::Time gameTime;
	float comboLevel;
	sf::Time comboTime;

	int rCharge;
	int gCharge;
	int bCharge;
public:
	Player();

	Player(sf::Time gTime);
	void update(sf::Time interval); //Timers count down.


	int getScore();
	void changeScore(int length, std::string colour);
	void changeScore(int length, Colour colour);
	int getAP(std::string colour);
	void changeAP(std::string colour, int apGain);
	void changeAP(Colour colour, int apGain);
	float getComboLV();

	sf::Time getComboTime();
	sf::Time getGameTime();

};
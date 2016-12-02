#pragma once

#include <string>

class Player
{
private:
	//const int COMBO_TIME_MAX = 10000;
	//const float ABILITY_POINT_MULTIPLIER = 0.01f;

	int score;
	int gameTime;
	float comboLevel;
	int comboTime;
	int rCharge;
	int gCharge;
	int bCharge;
public:
	Player();
	Player(int gTime);
	void update(); //Timers count down.

	int getScore();
	void changeScore(int length, std::string colour);
	int getAP(std::string colour);
	void changeAP(std::string colour, int apGain);
	float getComboLV();
	int getComboTime();
	int getGameTime();
};
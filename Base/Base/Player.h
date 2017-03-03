#pragma once

#include <string>
#include <SFML/System/Time.hpp>
#include "Colour.h"
class Player
{
private:
	///Player's current score.
	int score;

	///Player's score right before the last move made; for Reverse ability.
	int prevScore;

	///Time remaining until the game ends.
	sf::Time gameTime;

	///Combo multiplier used to boost score.
	float comboLevel;

	///Combo multiplier right before the last move made; for Reverse ability.
	float prevComboLevel;

	///Time remaining until the player's combo ends.
	sf::Time comboTime;

	///Determines the length of time for which the red ability, Fever, is active.
	sf::Time feverTime; 

	///Shows whether or not Fever is active in its advanced form, boosting point and combo gain.
	bool feverEX;

	///Bool that determines whether or not a Reverse is possible.
	bool reverseAvailable;

	///Points accrued for the red Fever ability.
	int rCharge;

	///Points accrued for the green Time Bonus ability.
	int gCharge;

	///Points accrued for the blue Reverse ability.
	int bCharge;

public:

	////////////////////////////////////////////////////////////
	/// \brief Default constructor.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	Player();

	////////////////////////////////////////////////////////////
	/// \brief Modified constructor.
	///
	/// \param Can set the amount of game time the player starts with.
	////////////////////////////////////////////////////////////
	Player(sf::Time gTime);

	////////////////////////////////////////////////////////////
	/// \brief Updates all in-game timers.
	///
	/// \param interval: Time since last update.
	////////////////////////////////////////////////////////////
	std::string update(sf::Time interval);

	////////////////////////////////////////////////////////////
	/// \brief Returns the player's current score.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	int getScore();

	////////////////////////////////////////////////////////////
	/// \brief Used to add points to the player's score.
	///
	/// \param Length and colour of the chain matched.
	////////////////////////////////////////////////////////////
	void changeScore(int length, Colour colour);

	////////////////////////////////////////////////////////////
	/// \brief Returns ability points for the specified ability.
	///
	/// \param Colour of the ability ("Red", "Green" or "Blue").
	////////////////////////////////////////////////////////////
	int getAP(std::string colour);

	////////////////////////////////////////////////////////////
	/// \brief Alters the current ability point value for the specified ability.
	///
	/// \param Colour of the ability ("Red", "Green" or "Blue") and amount to change it by.
	////////////////////////////////////////////////////////////
	void changeAP(std::string colour, int apGain);

	////////////////////////////////////////////////////////////
	/// \brief Returns the current combo level.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	float getComboLV();

	////////////////////////////////////////////////////////////
	/// \brief Consumes red ability points to boost the combo.
	///
	/// \param "ex" determines whether the advanced form is activated.
	////////////////////////////////////////////////////////////
	void fever(bool ex);

	////////////////////////////////////////////////////////////
	/// \brief Consumes blue ability points to undo the last move.
	///
	/// \param "ex" determines whether the advanced form is activated.
	////////////////////////////////////////////////////////////
	bool reverse(bool ex);

	////////////////////////////////////////////////////////////
	/// \brief Consumes green ability points to add game time.
	///
	/// \param "ex" determines whether the advanced form is activated.
	////////////////////////////////////////////////////////////
	void timeBonus(bool ex);

	////////////////////////////////////////////////////////////
	/// \brief Before each move, sets "previous" values equal to current ones.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void updatePrevious();

	////////////////////////////////////////////////////////////
	/// \brief Returns whether or not Fever is active in any form.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	bool getFeverLV();

	////////////////////////////////////////////////////////////
	/// \brief Returns number of seconds until combo ends.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	sf::Time getComboTime();

	////////////////////////////////////////////////////////////
	/// \brief Returns number of seconds until game ends.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	sf::Time getGameTime();
};

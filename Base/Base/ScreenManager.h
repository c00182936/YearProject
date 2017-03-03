#pragma once
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include "MainMenu.h"
#include "GameOverScreen.h"
class ScreenManager
{//will manage and iterate between screens
private:	
	///Reference to game window.
	sf::RenderWindow * window;

	///Menu scene that allows the player to begin playing or quit.
	MainMenu menu;

	///Game scene - main point of interaction.
	GameScreen screen;

	///Screen that displays once the game timer runs out.
	GameOverScreen gameOver;

	///Indicates which screen is currently active.
	std::string currentScreen;

	///Message received from game events that determines scene actions.
	std::string message;

public:
	////////////////////////////////////////////////////////////
	/// \brief Default constructor.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	ScreenManager();

	////////////////////////////////////////////////////////////
	/// \brief Modified constructor.
	///
	/// \param Sets game window for "window" pointer's use.
	////////////////////////////////////////////////////////////
	ScreenManager(sf::RenderWindow &win);

	////////////////////////////////////////////////////////////
	/// \brief Updates the current scene.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void update();

	////////////////////////////////////////////////////////////
	/// \brief Draws the elements of the current scene.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void draw();

	////////////////////////////////////////////////////////////
	/// \brief Checks "message" and performs actions based on its instruction.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void checkStringCases();

	////////////////////////////////////////////////////////////
	/// \brief Destructor function.
	///
	/// \param None
	////////////////////////////////////////////////////////////
	~ScreenManager();
};


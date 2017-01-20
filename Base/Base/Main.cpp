#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "GameScreen.h"
#include "MainMenu.h"
#include "ButtonManager.h"
#include "MainMenu.h"
#include "ScreenManager.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
	window.setFramerateLimit(30);
	sf::Texture sprite;
	//MenuButton butn = MenuButton("cumberbumber", "Assets/Sprites/play.png", sf::FloatRect(30, 30, 100, 300));
	//ButtonManager btn = ButtonManager();
	//MainMenu menu = MainMenu("Menu");
	ScreenManager manager = ScreenManager(window);
	if (!sprite.loadFromFile("Assets/Sprites/sprite.png"))
	{
		
	}
	sf::Sprite testSprite;
	testSprite.setTexture(sprite);
	testSprite.setScale(sf::Vector2f(0.7f, 0.7f));
	// run the program as long as the window is open
	while (window.isOpen())
	{
		
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			
			//menu.update(window);
			//btn.update(window);
		}

		window.clear();
		manager.update();
		//window.draw(testSprite);
		//btn.draw(window);
		//menu.draw(window);
		manager.draw();
		window.display();

	}

	//system("PAUSE");

}
#include "ButtonManager.h"



ButtonManager::ButtonManager()
{


}

std::string ButtonManager::update(sf::RenderWindow &win)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousePos = sf::Vector2f(sf::Mouse::getPosition(win));
		std::cout << mousePos.x << " " << mousePos.y << std::endl;
		for (size_t i = 0; i < ButtonVector.size(); i++)
		{
			if (ButtonVector[i].checkOver(mousePos) == true)
			{
				std::cout << "button pressed " + *ButtonVector[i].getAction() << std::endl;
				currentMessage = *ButtonVector[i].getAction();

			}
		}
	}
	else
	{
		currentMessage = "";
	}
	return currentMessage;
}

void ButtonManager::draw(sf::RenderWindow & win)
{
	for (int i = 0; i < ButtonVector.size(); i++)
	{
		ButtonVector[i].draw(win);
	}
}

std::string ButtonManager::SelectButton()
{
	return std::string();
}

void ButtonManager::AddButton(std::string title, sf::Vector2f position, std::string location)
{
	
	ButtonVector.push_back(MenuButton(title, location, position));
}


ButtonManager::~ButtonManager()
{
}

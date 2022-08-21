#include"menu.h"
#include"Button.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<map>


void menu(sf::RenderWindow& window)
{
	mousePosition mousePos = mousePosition::other;
	bool isMenu = true;
	sf::Font font;
	font.loadFromFile("CyrilicOld.TTF");

	std::map<mousePosition, Button*> buttons;
	buttons[mousePosition::newGame] = new Button("Start new game", { 0,0 });
	buttons[mousePosition::continueGame] = new Button("Continue game", { 0,50 });
	buttons[mousePosition::instruction] = new Button("instruction", { 0,100 });


	while (isMenu)
	{
		for (auto i = buttons.begin(); i != buttons.end(); ++i)
			i->second->setColor(sf::Color::Blue);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}

			/*if (startGameButton.getButtonBorders().contains(sf::Mouse::getPosition(window)))
			{
				startGameButton.setColor(sf::Color::Red);
				mousePos = mousePosition::newGame;
			}
			else if (instructionButton.getButtonBorders().contains(sf::Mouse::getPosition(window)))
			{
				instructionButton.setColor(sf::Color::Red);
				mousePos = mousePosition::instruction;
			}*/
			for (auto i = buttons.begin(); i != buttons.end(); ++i)
			{
				if (i->second->getButtonBorders().contains(sf::Mouse::getPosition(window)))
				{
					i->second->setColor(sf::Color::Red);
					mousePos = i->first;
					break;
				}
			}


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				switch (mousePos)
				{
				case mousePosition::newGame:
					return;
					break;
				case mousePosition::continueGame:
					return;
					break;
				case mousePosition::instruction:
					instruction(window);
					break;
				}
			}

			window.clear();
			for (auto i = buttons.begin(); i != buttons.end(); ++i)
				i->second->draw(window);
			window.display();
		}
	}

}

void instruction(sf::RenderWindow& window)
{

}
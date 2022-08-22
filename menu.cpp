#include"menu.h"
#include"Button.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<map>
#include<process.h> // for exit()


bool menu(sf::RenderWindow& window) // return true if new game, false otherwise
{
	mousePosition mousePos = mousePosition::other;
	//bool isMenu = true;
	sf::Font font;
	font.loadFromFile("CyrilicOld.TTF");

	std::map<mousePosition, Button*> buttons;
	buttons[mousePosition::newGame] = new Button("Start new game", { 0,50 });
	std::ifstream inputStream("dat.dat");
	if(inputStream)
		buttons[mousePosition::continueGame] = new Button("Continue game", { 0,100 });
	buttons[mousePosition::instruction] = new Button("instruction", { 0,150 });
	buttons[mousePosition::quit] = new Button("Quit", { 200, 380 });

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("menu.png");
	sf::Sprite backgroundImage;
	backgroundImage.setTexture(backgroundTexture);

	while (true)
	{
		for (auto i = buttons.begin(); i != buttons.end(); ++i)
			i->second->setColor(sf::Color::Blue);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}

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
					return true;
				case mousePosition::continueGame:
					return false;
				case mousePosition::instruction:
					instruction(window);
					break;
				case mousePosition::quit:
					window.close();
					exit(0);
					break;
				}
			}

			window.clear();
			window.draw(backgroundImage);
			for (auto i = buttons.begin(); i != buttons.end(); ++i)
				i->second->draw(window);
			window.display();
		}
	}
}

void instruction(sf::RenderWindow& window)
{
	const char* instructionText = "Sudoku is played on a grid of 9 x 9 \nspaces. Within the rows and columns \nare 9 squares (made up of 3 x 3 \nspaces). Each row, column and square \n(9 spaces each) needs to be filled \nout with the numbers 1-9, without \nrepeating any numbers within \nthe row, column or square.";
	Button quit("Got it", { 200,420 });
	mousePosition mousePos = mousePosition::other;
	sf::Font font; 
	font.loadFromFile("CyrilicOld.TTF");
	sf::Text text;
	text.setFont(font);
	text.setString(instructionText);
	text.setColor(sf::Color::Blue);
	text.setPosition({0,0});

	while (true)
	{
		quit.setColor(sf::Color::Blue);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
		}

		if (quit.getButtonBorders().contains(sf::Mouse::getPosition(window)))
		{
			mousePos = mousePosition::quit;
			quit.setColor(sf::Color::Red);
		}
		else
			mousePos = mousePosition::other;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePos == mousePosition::quit)
			return;

		window.clear();
		quit.draw(window);
		window.draw(text);
		window.display();
	}
}
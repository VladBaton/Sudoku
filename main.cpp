#include<iostream>
#include<fstream>
#include"SudokuMap.h"
#include"UnitTests.h"
#include"SudokuGame.h"
#include <SFML\Graphics.hpp>
#include "drawSudoku.h"
#include "menu.h"
#include"Button.h"


int main()
{
	try
	{
		sf::RenderWindow window(sf::VideoMode(450, 450), "Sudoku");
		bool isNewGame = menu(window);
		SudokuGame gama;
		if (isNewGame)
		{
			gama.mixMap();
			gama.setGame();
		}
		else
			gama = *(new SudokuGame("dat.dat"));
		Cell** cells; int dim;
		std::tie(cells, dim) = gama.getMap();
		sf::Vector2i redCell = { -1,0 };
		sf::Vector2i clickedCell = { -1,0 }; //keeps coords of Cell that had been clicked
		bool isValueChanged = false; // True if user changed value of Cell and didnt press enter yet
		while (window.isOpen())
		{
			if (redCell.x != -1)
				cells[redCell.x][redCell.y].textColor = sf::Color::Black;
			if (clickedCell.x != -1)
				cells[clickedCell.x][clickedCell.y].texture.loadFromFile("cellButtonClicked.png");

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			if (!(mouse.x > 450 || mouse.x < 0 || mouse.y > 450 || mouse.y < 0))
			{
				redCell.x = mouse.y / 50;
				redCell.y = mouse.x / 50;
				cells[mouse.y / 50][mouse.x / 50].textColor = sf::Color::Red;
			}
			else
				redCell.x = -1;

			if (!isValueChanged && sf::Mouse::isButtonPressed(sf::Mouse::Left) && redCell.x != -1)
			{
				if (clickedCell.x != -1)
					cells[clickedCell.x][clickedCell.y].texture.loadFromFile("cellButton.png");
				clickedCell = redCell;
			}

			for (int key = sf::Keyboard::Num0; key <= sf::Keyboard::Num9; key++)
			{
				sf::Keyboard::Key trueKey = static_cast<sf::Keyboard::Key>(key);
				if (sf::Keyboard::isKeyPressed(trueKey) && clickedCell.x != -1 &&
					cells[clickedCell.x][clickedCell.y].value < 1)
				{
					cells[clickedCell.x][clickedCell.y].value = key - 26;
					isValueChanged = true;
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				if (clickedCell.x != -1)
				{
					cells[clickedCell.x][clickedCell.y].texture.loadFromFile("cellButton.png");
					clickedCell.x = -1;
				}
			}

			if (isValueChanged && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				bool result = gama.insertNumber(cells[clickedCell.x][clickedCell.y].value,
					clickedCell.x, clickedCell.y);
				if (!result)
					cells[clickedCell.x][clickedCell.y].value = 0;
				isValueChanged = false;

			}


			window.clear();
			for (int i = 0; i < dim; i++)
				for (int j = 0; j < dim; j++)
					cells[i][j].draw(window);
			window.display();
		}
		gama.saveGame();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	system("pause");
	return 0;
}
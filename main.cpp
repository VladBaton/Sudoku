#include<iostream>
#include<fstream>
#include"SudokuMap.h"
#include"UnitTests.h"
#include"SudokuGame.h"
#include <SFML\Graphics.hpp>
#include "drawSudoku.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Sudoku");
	Cell myCell(4, 0, 0);
	while (true)
	{
		sf::Event event;
		while(window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				return 0;
		window.clear();
		myCell.draw(window);
		window.display();
	}
	return 0;
}
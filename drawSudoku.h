#pragma once
#include<SFML\Graphics.hpp>


struct Cell // Cell of sudoku map
{
	int value;
	sf::Color textColor;
	sf::RectangleShape rectangle;
	sf::Texture texture;
	sf::Font font;
	Cell();
	//Cell(int val);
	Cell(int val, float x, float y, int w = 50, int h = 50);
	void draw(sf::RenderWindow& window);
};
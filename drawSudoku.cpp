#include "drawSudoku.h"
#include <string>

//Cell::Cell():value(-1), rectangle(sf::RectangleShape(sf::Vector2f(0,0))){}
//Cell::Cell(int val): value(val), rectangle(sf::RectangleShape(sf::Vector2f(0, 0))) {}
Cell::Cell(int val, float x, float y, int w, int h) : value(val), rectangle(sf::RectangleShape(sf::Vector2f(w, h))), texture()
{
	rectangle.setPosition(sf::Vector2f(x, y));
	texture.loadFromFile("cellButton.png");
	rectangle.setTexture(&texture);
	font.loadFromFile("CyrilicOld.TTF");
}
void Cell::draw(sf::RenderWindow& window)
{
	sf::Text text("", font, 30);
	if (value > 0)
		text.setString(std::to_string(value));
	text.setColor(sf::Color::Black);
	sf::Vector2f pos = rectangle.getPosition();
	pos.x += 15; pos.y += 5;
	text.setPosition(pos);
	window.draw(rectangle);
	window.draw(text);
}
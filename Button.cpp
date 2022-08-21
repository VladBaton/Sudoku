#include"Button.h"
#include<SFML/Graphics.hpp>

Button::Button():buttonFont(), buttonText(), buttonBorders(sf::IntRect(0, 0, 0, 0)) {}
Button::Button(sf::String str):Button()
{
	buttonFont.loadFromFile("CyrilicOld.TTF");
	buttonText.setFont(buttonFont);
	buttonText.setString(str);
	buttonText.setColor(sf::Color::Blue);
	buttonBorders.width = str.getSize() * 15;
	buttonBorders.height = 30;
}

Button::Button(sf::String str, sf::Vector2f position) :Button(str)
{
	buttonText.setPosition(position);
	buttonBorders.left = position.x;
	buttonBorders.top = position.y;
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(buttonText);
}

sf::IntRect Button::getButtonBorders() const
{
	return buttonBorders;
}
void Button::setColor(sf::Color color)
{
	buttonText.setColor(color);
}

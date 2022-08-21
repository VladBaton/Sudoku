#pragma once
#include<SFML\Graphics.hpp>



class Button
{
private:
	sf::Font buttonFont;
	sf::Text buttonText;
	sf::IntRect buttonBorders;
public:
	Button();
	Button(sf::String str);
	Button(sf::String str, sf::Vector2f position);
	void draw(sf::RenderWindow& window) const;
	sf::IntRect getButtonBorders() const;
	void setColor(sf::Color color);

};

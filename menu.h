#pragma once
namespace sf { class RenderWindow; };

enum class mousePosition { newGame, continueGame, instruction, quit, other };

void menu(sf::RenderWindow& window);

void instruction(sf::RenderWindow& window);
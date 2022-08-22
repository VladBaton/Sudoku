#pragma once
namespace sf { class RenderWindow; };

enum class mousePosition { newGame, continueGame, instruction, quit, other };

void instruction(sf::RenderWindow& window);

bool menu(sf::RenderWindow& window);

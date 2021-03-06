//
// Created by Krzysiek on 30/01/2022.
//

#include "Scoreboard.hpp"
#include <string>
#include <SFML/Graphics.hpp>


Scoreboard::Scoreboard(sf::Font& font, int xPos, int width)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(xPos + width / 10, 25);
	sf::Vector2<float> score_scale(1.5f, 1.5f);
	text.setScale(score_scale);
	text.setString("Lines: 0");
	this->text = text;
}

void Scoreboard::reactToEvent(EventType type, int data)
{
	switch (type)
	{
		case RowsCleared:
			this->lines += data;
			this->text.setString("Lines: " + std::to_string(lines));
			break;
		case Lost:
			this->text.setFillColor(sf::Color::Red);
			this->text.setString("Game lost. Score: " + std::to_string(lines));
			break;
		case EventType::GameStarted:
			this->lines = 0;
			this->text.setFillColor(sf::Color::White);
			this->text.setString("Lines: " + std::to_string(lines));
			break;
	}
}

sf::Text Scoreboard::getScore()
{
	return this->text;
}

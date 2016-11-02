/* score.cpp */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "score.hpp"

/* SCORE IMPLEMENTATION */

Score::Score()
	: score(0)
{};

Score::Score(const char * filename_)
	: filename(filename_)
{
	if (filename == 0)
	{
		throw std::invalid_argument("Empty filename");
	}
	std::ifstream inp(filename);
	if (!inp)
	{
		std::ofstream outp(filename);
		outp << 0;
		outp.close();
		inp.open(filename);
	}
	inp >> score;
	inp.close();
}

int Score::get_score() const
{
	return score;
}

void Score::upd_score(int score_)
{
	std::ifstream inp(filename);
	inp >> score;
	if (score_ > score)
	{
		inp.close();
		std::ofstream outp(filename);
		outp << score_;
		score = score_;
		outp.close();
	}
	else
	{
		inp.close();
	}
}

void Score::show_score_page(sf::RenderWindow & window)
{
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text score_text;
	score_text.setPosition(sf::Vector2f(100, 250));
	score_text.setFont(font);
	score_text.setCharacterSize(200);
	score_text.setColor(sf::Color::White);
	score_text.setString(std::to_string(score));
	sf::RectangleShape back;
	sf::Texture b_txtr;
	b_txtr.loadFromFile("images/empty.jpg");
	back.setPosition(sf::Vector2f(0, 0));
	back.setSize(sf::Vector2f(1280, 720));
	back.setTexture(&b_txtr);

	while (true)
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ((event.type == sf::Event::Closed) ||
				        (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				{
					return;
				}
			}

			window.clear();
			window.draw(back);
			window.draw(score_text);
			window.display();
		}
	}
}

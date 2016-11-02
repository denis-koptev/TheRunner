/* main.cpp */

#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "game.hpp"
#include "menu.hpp"
#include "score.hpp"
#include "defines.hpp"

void play_game(sf::RenderWindow &, Score &);
void show_titles(sf::RenderWindow &);

int main()
{
	srand(static_cast<unsigned>(time(0)));

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Runner"/*, sf::Style::Fullscreen*/);
	Menu menu(menu_name, ctrl_image);
	Score score(score_path);

	while (true)
	{
		switch (menu.start(window))
		{
			case 0:
			{
				play_game(window, score);
				break;
			}
			case 1:
			{
				score.show_score_page(window);
				break;
			}
			case 2:
			{
				show_titles(window);
				break;
			}
			case 3:
			{
				return 0;
			}
		}
	}

	return 0;
}

void play_game(sf::RenderWindow & window, Score & score)
{
	try
	{
		Game game(init_delay);

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
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
					{
						game.jump_made();
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
					{
						game.pause();
					}
				}

				window.clear();

				game.make_step(window);
				game.show_score(window);
				if (game.is_collision())
				{
					score.upd_score(game.get_score());
					return;
				}
				window.display();
			}
		}
	}
	catch (const std::exception & exc)
	{
		std::cerr << exc.what() << std::endl;
		return;
	}
}

void show_titles(sf::RenderWindow & window)
{
	sf::RectangleShape titles;
	sf::Texture txtre;
	txtre.loadFromFile(titles_name);
	titles.setTexture(&txtre);
	titles.setPosition(sf::Vector2f(0, 0));
	titles.setSize(sf::Vector2f(1280, 720));

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
			window.draw(titles);
			window.display();
		}
	}
}
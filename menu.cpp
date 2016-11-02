/* menu.cpp */

#include <SFML/Graphics.hpp>
#include "menu.hpp"

/* MENU IMPLEMENTATION*/

Menu::Menu(const char * menu_n, const char * ctrl_n)
	: back(menu_n, 0, 0, 1280, 720),
	  ctrl(ctrl_n, 0, 255, 1280, 100),
	  curr(0)
{};

void Menu::show(sf::RenderWindow & window)
{
	ctrl.set_pos(0, 255 + 85 * curr);
	back.show(window);
	ctrl.show(window);
}

int Menu::start(sf::RenderWindow & window)
{
	while (true)
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				{
					if (curr < 3)
					{
						++curr;
					}
					else
					{
						curr = 0;
					}
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				{
					if (curr > 0)
					{
						--curr;
					}
					else
					{
						curr = 3;
					}
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
				{
					return curr;
				}
			}
			window.clear();
			show(window);
			window.display();
		}
	}
	return 0;
}

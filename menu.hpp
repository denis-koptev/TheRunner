/* menu.hpp */

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "image.hpp"

/* MENU DECLARATION */

class Menu
{
	public:

		Menu(const char *, const char *);

		int start(sf::RenderWindow &);
		void show(sf::RenderWindow &);

	private:

		Image back;
		Image ctrl;

		int curr;
};

#endif
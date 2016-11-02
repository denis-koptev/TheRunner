/*buildings.hpp*/

#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <SFML/Graphics.hpp>
#include "image.hpp"

/* BUILDINGS DECLARATION */

class Buildings : public Image
{
	public:

		Buildings();
		explicit Buildings(const char * img_name, int x_pos = 0, int y_pos = 0,
		                   int x_size = 0, int y_size = 0);

		void show(sf::RenderWindow &);

};

#endif
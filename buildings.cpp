/* buildings.cpp */

#include <SFML/Graphics.hpp>
#include "buildings.hpp"

/* BUILDINGS IMPLEMENTATION */

Buildings::Buildings()
{};

Buildings::Buildings(const char * img_name, int x_pos, int y_pos,
                     int x_size, int y_size)
	: Image(img_name, x_pos, y_pos, x_size, y_size)
{}

void Buildings::show(sf::RenderWindow & window)
{
	window.draw(img);
	move(1280);
	window.draw(img);
	move(-1280);
	if (get_x() <= -1280)
	{
		set_pos(0, static_cast<int>(img.getPosition().y));
	}
}

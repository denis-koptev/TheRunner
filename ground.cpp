/* ground.cpp */

#include <SFML/Graphics.hpp>
#include "ground.hpp"

/* GROUND IMPLEMENTATION */

Ground::Ground()
{};

Ground::Ground(const char * img_name, int x_pos, int y_pos,
               int x_size, int y_size)
	: Buildings(img_name, x_pos, y_pos, x_size, y_size)
{};

/* ground.hpp */

#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include "buildings.hpp"

/* GROUND DECLARATION */

class Ground : public Buildings
{
	public:
		Ground();
		Ground(const char * img_name, int x_pos = 0, int y_pos = 0,
		       int x_size = 0, int y_size = 0);

};

#endif
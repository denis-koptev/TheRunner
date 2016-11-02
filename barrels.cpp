/* barrels.cpp */

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "barrels.hpp"

/* BARRELS IMPLEMENTATION */

Barrels::Barrels()
{};

Barrels::Barrels(const char * img_name, int y_pos,
                 int x_size, int y_size)
	: counted(0)
{
	if (img_name == 0)
	{
		throw std::invalid_argument("Empty filename!");
	}
	Example.set_pos(1280, y_pos);
	Example.set_size(x_size, y_size);
	Example.set_image(img_name);
}

void Barrels::add()
{
	barrels.push_back(Example);
}

bool Predicate(const Image & this_img)
{
	return this_img.get_x() == -300;
}

void Barrels::update()
{
	std::remove_if(barrels.begin(), barrels.end(), Predicate);
}

void Barrels::move(int dx)
{
	for (std::vector<Image>::iterator it = barrels.begin(); it != barrels.end(); ++it)
	{
		it->move(dx);
	}
}

void Barrels::show(sf::RenderWindow & window)
{
	for (std::vector<Image>::iterator it = barrels.begin(); it != barrels.end(); ++it)
	{
		it->show(window);
	}
}

int Barrels::get_last_pos() const
{
	if (!barrels.empty())
	{
		return barrels.back().get_x();
	}
	else
	{
		return 0;
	}
}

bool Barrels::is_dangerous() const
{
	for (std::vector<Image>::const_iterator it = barrels.begin(); it != barrels.end(); ++it)
	{
		if ((it->get_x() > (540 - 50)) && (it->get_x() < (540 + 60)))
		{
			return true;
		}
	}
	return false;
}
/* image.cpp */

#include <SFML/Graphics.hpp>
#include "image.hpp"

/* IMAGE IMPLEMENTATION */

Image::Image()
{};

Image::Image(const sf::RectangleShape & img_, const sf::Texture & txtr_)
	: img(img_), txtr(txtr_)
{}

Image::Image(const char * img_name, int x_pos, int y_pos,
             int x_size, int y_size)
{
	if (img_name == 0)
	{
		throw std::invalid_argument("Empty filename!");
	}
	img.setPosition(
	    sf::Vector2f(static_cast<float>(x_pos), static_cast<float>(y_pos))
	);
	img.setSize(
	    sf::Vector2f(static_cast<float>(x_size), static_cast<float>(y_size))
	);
	txtr.loadFromFile(img_name);
	img.setTexture(&txtr);
}

void Image::show(sf::RenderWindow & window)
{
	window.draw(img);
}

void Image::set_pos(int x_pos, int y_pos)
{
	img.setPosition(
	    sf::Vector2f(static_cast<float>(x_pos), static_cast<float>(y_pos))
	);
}

void Image::set_size(int x_size, int y_size)
{
	img.setSize(
	    sf::Vector2f(static_cast<float>(x_size), static_cast<float>(y_size))
	);
}

void Image::move(int d_x, int d_y)
{
	img.setPosition(
	    sf::Vector2f(img.getPosition().x + d_x, img.getPosition().y + d_y)
	);
}

int Image::get_x() const
{
	return static_cast<int>(img.getPosition().x);
}

int Image::get_y() const
{
	return static_cast<int>(img.getPosition().y);
}

void Image::set_image(const char * img_name)
{
	txtr.loadFromFile(img_name);
	img.setTexture(&txtr);
}
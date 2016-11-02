/* image.hpp */

#ifndef IMAGE_H
#define IMAGE_H

#include <stdexcept>
#include <SFML/Graphics.hpp>

/* IMAGE DECLARATION */

class Image
{
	public:

		Image();
		Image(const sf::RectangleShape &, const sf::Texture &);
		explicit Image(const char * img_name, int x_pos = 0, int y_pos = 0,
		               int x_size = 0, int y_size = 0);

		void show(sf::RenderWindow &);

		void set_pos(int, int);
		void set_size(int, int);
		void set_image(const char *);
		void move(int d_x = 0, int d_y = 0);

		int get_x() const;
		int get_y() const;

	protected:

		sf::RectangleShape img;
		sf::Texture txtr;
};

#endif	// IMAGE_H
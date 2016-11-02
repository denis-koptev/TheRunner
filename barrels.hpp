/* barrels.hpp */

#ifndef BARRELS_H
#define BARRELS_H

#include <SFML/Graphics.hpp>
#include "image.hpp"

/* BARRELS DECLARATION */

class Barrels
{
	public:

		Barrels();
		explicit Barrels(const char * img_name, int y_pos = 0,
		                 int x_size = 0, int y_size = 0);

		void add();
		void move(int);
		void update();
		void show(sf::RenderWindow &);
		int get_last_pos() const;
		bool is_dangerous() const;

	private:

		std::vector<Image> barrels;
		Image Example;
		size_t counted;
};

#endif
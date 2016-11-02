/* player.hpp */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "image.hpp"

/* PLAYER DECLARATION */

class Player
{
	public:

		Player();
		explicit Player(const char * img_name1, const char * img_name2,
		                int x_pos = 0, int y_pos = 0, int x_size = 0, int y_size = 0);

		bool jump(bool &);
		void show(sf::RenderWindow &, bool);
		int get_y() const;

	private:

		Image player1;
		Image player2;

		bool jumped;
};

#endif
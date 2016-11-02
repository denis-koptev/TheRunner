/* player.cpp */

#include <SFML/Graphics.hpp>
#include "player.hpp"

//********** PLAYER IMPLEMENTATION **********//

Player::Player()
{};

Player::Player(const char * img_name1, const char * img_name2,
               int x_pos, int y_pos, int x_size, int y_size)
	: player1(img_name1, x_pos, y_pos, x_size, y_size),
	  player2(img_name2, x_pos, y_pos, x_size, y_size),
	  jumped(false)
{}

bool Player::jump(bool & active)
{
	static int delta = 0;
	//static bool incr = true;
	jumped = active;
	if (active)
	{
		if (delta == -19)
		{
			active = false;
			delta = 0;
			return active;
		}
		if (player2.get_y() == 420)
		{
			delta = 20;
		}

		--delta;
		player1.move(0, -delta);
		player2.move(0, -delta);
	}
	return active;
}

void Player::show(sf::RenderWindow & window, bool is_paused)
{
	static int current = 0;
	if (current <= 7 && !jumped)
	{
		player1.show(window);
	}
	else
	{
		player2.show(window);
	}
	if (current > 14)
	{
		current = 0;
	}
	if (!is_paused)
	{
		++current;
	}
}

int Player::get_y() const
{
	return player1.get_y();
}

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Image.h"

//********** PLAYER DECLARATION **********//

/*
Лучше не наследовать, а содержать композицию двух картинок
Тогда игра будет работать быстрее, т.к. переключение картинок с
постоянным чтением изображения из файла - слишком долго
*/

class Player : public Image
{
	public:

		inline Player();
		inline explicit Player(const char * img_name, int x_pos = 0, int y_pos = 0,
		                       int x_size = 0, int y_size = 0);

		inline bool jump(bool &);

};

//********** PLAYER IMPLEMENTATION **********//

inline Player::Player()
{};

inline Player::Player(const char * img_name, int x_pos, int y_pos,
                      int x_size, int y_size)
	: Image(img_name, x_pos, y_pos, x_size, y_size)
{}

inline bool Player::jump(bool & active)
{
	static int delta = 0;
	static bool incr = true;
	if (active)
	{
		if (delta == -19)
		{
			active = false;
			delta = 0;
			return active;
		}
		if (get_y() == 420)
		{
			delta = 20;
		}

		--delta;
		move(0, -delta);
	}
	return active;
}

#endif
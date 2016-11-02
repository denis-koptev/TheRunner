/* game.hpp */

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "image.hpp"
#include "buildings.hpp"
#include "ground.hpp"
#include "player.hpp"
#include "barrels.hpp"
#include "defines.hpp"

/* GAME DECLARATION */

class Game
{
	public:

		Game(int);

		bool make_step(sf::RenderWindow &);
		void jump_made();
		void pause();
		bool is_collision() const;
		int get_score() const;
		void show_score(sf::RenderWindow &);

	private:

		Image bg;
		Buildings blds;
		Ground grnd;
		Player me;
		Barrels brls;

		sf::Text score_text;
		sf::Font font;

		int score;
		int delay;
		bool jumped;
		bool paused;
};

#endif
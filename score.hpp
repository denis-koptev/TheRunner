/* score.hpp */

#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <fstream>

/* SCORE DECLARATION */

class Score
{
	public:

		Score();
		Score(const char *);

		void upd_score(int);
		int get_score() const;
		void show_score_page(sf::RenderWindow &);

	private:

		int score;
		const char * filename;
};

#endif
/* game.cpp */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.hpp"

/* GAME IMPLEMENTATION */

Game::Game(int start_delay)
	: bg(bg_name, 0, 0, 1280, 720),
	  blds(bld_name, 0, 250, 1280, 228),
	  grnd(grnd_name, 0, 478, 1280, 250),
	  me(me_name1, me_name2, 540, 420, 112, 139),
	  brls(brl_name, 450, 91, 130),
	  score(0), delay(start_delay),
	  jumped(false), paused(false)
{
	brls.add();

	score_text.setString(std::to_string(score));
	score_text.setPosition(sf::Vector2f(0, 0));
	score_text.setCharacterSize(20);
	font.loadFromFile(font_path);
	score_text.setFont(font);
	score_text.setColor(sf::Color::Black);
};

bool Game::make_step(sf::RenderWindow & window)
{
	bg.show(window);
	blds.show(window);
	grnd.show(window);
	brls.show(window);
	me.show(window, paused);
	if (paused)
	{
		return true;
	}
	brls.move(-7);
	brls.update();
	blds.move(-1);
	jumped = me.jump(jumped);
	grnd.move(-7);

	if ((rand() % 50) == 0 && brls.get_last_pos() < 1000)
	{
		brls.add();
	}

	++score;
	sf::sleep(sf::Time(sf::milliseconds(delay)));
	return true;
}

void Game::jump_made()
{
	jumped = true;
}

void Game::pause()
{
	paused = !paused;
}

bool Game::is_collision() const
{
	if ((me.get_y() + 139 > 460) && brls.is_dangerous())
	{
		sf::sleep(sf::Time(sf::milliseconds(1000)));
		return true;
	}
	return false;
}

int Game::get_score() const
{
	return score;
}

void Game::show_score(sf::RenderWindow & window)
{
	score_text.setString(std::to_string(score));
	window.draw(score_text);
}

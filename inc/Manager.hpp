
#pragma once
#include <SFML/Graphics.hpp>
#include "Jumper.hpp"

class Manager  
{
	private:
	sf::RenderWindow &_win;
	Jumper _jumper;
	public:

		Manager(sf::RenderWindow &win);
		~Manager();

		void run();

};

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Jumper  
{
	private:
	static const int CAP = 75;
	sf::Vector2f SPEED;

	sf::RectangleShape _obj;
	sf::Texture* _textPicture;
	sf::RenderWindow *_win;

	void move(sf::Time &time);
	void init_pic();
	void init_obj();
	void check_col();
	void change_bg();

	public:

		Jumper();
		~Jumper();
		void set_win(sf::RenderWindow& win);
		void update(sf::Time &time);

};
#include <SFML/Graphics.hpp>
#include "Manager.hpp"

int main()
{
    sf::RenderWindow win(sf::VideoMode(400, 400), "Honor Showcase");
    Manager _man(win);
    _man.run();

    return 1;
}
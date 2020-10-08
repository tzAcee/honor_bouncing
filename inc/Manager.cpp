#include "Manager.hpp"  

Manager::Manager(sf::RenderWindow &win):_win(win)
{
    _jumper.set_win(_win);
}

Manager::~Manager()
{

}

void Manager::run()
{
    sf::Clock deltaClock;

    while(_win.isOpen())
    {
        sf::Time tm = deltaClock.restart();
        sf::Event ev;
        while(_win.pollEvent(ev))
            if(ev.type == sf::Event::Closed)
                _win.close();

        _win.clear();

        _jumper.update(tm);

        _win.display();

    }
}
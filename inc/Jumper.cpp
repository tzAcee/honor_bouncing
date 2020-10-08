#include "Jumper.hpp"  

Jumper::Jumper()
{
    _textPicture = new sf::Texture; 
    srand(time(0));
    SPEED = sf::Vector2f(std::rand()%CAP+1, std::rand()%CAP+1);
    init_pic();
}

Jumper::~Jumper()
{
    delete _textPicture;
}

void Jumper::init_pic()
{
    if(!_textPicture->loadFromFile("/home/fleexo/_dev/c++/honor_showcase/assets/honor.png")) // TODO
    {
        std::cout << "File could not be loaded.";
    }
    init_obj();
}

void Jumper::init_obj()
{
    _obj.setSize(sf::Vector2f(75, 25));
    _obj.setTexture(_textPicture);
    _obj.setFillColor(sf::Color::White);
}

void Jumper::set_win(sf::RenderWindow& win)
{
    _win = &win;
}

void Jumper::change_bg()
{
    _obj.setFillColor(sf::Color(std::rand()%250, std::rand()%250, std::rand()%250));
}

void Jumper::check_col()
{
    float x = _obj.getPosition().x;
    float y = _obj.getPosition().y;

    float width = _obj.getSize().x;
    float height = _obj.getSize().y;

    bool collided = false;

    if(x >= _win->getSize().x-width)
    {
        SPEED = sf::Vector2f(-SPEED.x, SPEED.y);
        _obj.setPosition(sf::Vector2f(_win->getSize().x-width-1, y));
        collided = true;
    }
    else if(x <= 0)
    {
        SPEED = sf::Vector2f(-SPEED.x, SPEED.y);
        _obj.setPosition(sf::Vector2f(2, y));
        collided = true;
    }

    if(y >= _win->getSize().y-height)
    {
        SPEED = sf::Vector2f(SPEED.x, -SPEED.y);
        _obj.setPosition(sf::Vector2f(x, _win->getSize().y-height-1));
        collided = true;
    }
    else if(y <= 0)
    {
        SPEED = sf::Vector2f(SPEED.x, -SPEED.y);
        _obj.setPosition(sf::Vector2f(x, 2));
        collided = true;
    }

    if(collided)
        change_bg();
}

void Jumper::move(sf::Time &time)
{
    _obj.move(SPEED.x*time.asSeconds(), SPEED.y*time.asSeconds());

    check_col();
}

void Jumper::update(sf::Time &time)
{
    move(time);
    _win->draw(_obj);
}
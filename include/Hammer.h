#ifndef HAMMER_H
#define HAMMER_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>

class Hammer
{
private:
    sf::RenderWindow*           m_window;

    sf::Texture                 m_texture_hammer;
    sf::Sprite                  m_sprite_hammer;
public:
    Hammer(sf::RenderWindow* window);

    void                        update();
    void                        draw();
    sf::Vector2f                getPosition();
};

#endif // HAMMER_H

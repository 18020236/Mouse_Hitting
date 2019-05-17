#ifndef POWER_H
#define POWER_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

class Power
{
private:
    sf::RenderWindow*           m_window;
    sf::Sprite                  m_sprite;
    sf::Clock                   m_clock;
    float                       m_speed;
public:
    Power(sf::RenderWindow* window, sf::Texture& texture, float speed);
    void                        update(float speed);
    void                        draw();
    sf::Vector2f                getPosition();
};


#endif // POWER_H

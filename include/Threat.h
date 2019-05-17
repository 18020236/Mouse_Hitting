#ifndef THREAT_H
#define THREAT_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

class Threat
{
private:
    sf::RenderWindow*           m_window;
    sf::Sprite                  m_sprite;
    sf::Clock                   m_clock;

    float                       m_speed;
    float                       m_Frame;

    std::vector <sf::IntRect>   m_Frames;
public:
    Threat(sf::RenderWindow* window, sf::Texture& texture, float speed);
    void                        update(float speed);
    void                        draw();
    sf::Vector2f                getPosition();
};

#endif // THREAT_H

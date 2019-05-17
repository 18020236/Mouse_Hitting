#ifndef BOSS_THREAT_H
#define BOSS_THREAT_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

class Boss_Threat
{
private:
    sf::RenderWindow*           m_window;

    sf::Sprite                  m_sprite;
    sf::Clock                   m_clock;

    float                       m_speed;
    float                       m_Frame;
    std::vector <sf::IntRect>   m_Frames;
public:
    Boss_Threat(sf::RenderWindow* window, sf::Texture& texture);
    void                        update(float speed);
    void                        draw();
    int                         boss_life = 10;
    sf::Vector2f                getPosition();
};

#endif // BOSS_THREAT_H

#ifndef _Threat_H_
#define _Threat_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>

class Threat
{
private:
    sf::RenderWindow*           m_window;
    sf::Sprite                  m_sprite;
public:
    Threat(sf::RenderWindow* window, sf::Texture& texture);
    void                        update();
    void                        draw();

    sf::Vector2f                getPosition();

};


#endif //  _Threat_H_

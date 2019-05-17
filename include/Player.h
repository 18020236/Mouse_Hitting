#ifndef PLAYER_H
#define PLAYER_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>

class Player
{
public:
    Player(sf::RenderWindow* window);

    void                update();
    void                draw();
private:
    sf::RenderWindow*               m_window;
//    sf::Texture                     m_texture;
//    sf::Sprite                      m_sprite;
};

#endif // PLAYER_H

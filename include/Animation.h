#ifndef _Animation_H_
#define _Animation_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>

class Animation
{
private:
    sf::RenderWindow*           m_window;
    sf::Sprite                  m_sprite;
    float                       m_speed;
    float                       m_Frame;
    std::vector <sf::IntRect>   m_Frames;

public:
    Animation(sf::RenderWindow * window, sf::Texture &t, int column, int line, int width, int height, float speed, int frames, float scale, sf::Vector2f position);

    void update();
    void draw();

    bool checkEnd();

    void setPosition(sf::Vector2f position);
};

#endif //   _Animation_H_

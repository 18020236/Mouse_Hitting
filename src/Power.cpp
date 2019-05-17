#include "Power.h"

Power::Power(sf::RenderWindow* window, sf::Texture& texture, float speed)
{
    this->m_window = window;
    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(850/2, 520/2);
    this->m_sprite.setScale(0.25, 0.25);

    this->m_speed = speed;
    float rand = std::rand() % 5;
    int pos = 122 + rand*180;
    this->m_sprite.setPosition(1809, pos);

}


void Power::update(float speed)
{
    this->m_sprite.move(- speed, 0);
}

void Power::draw()
{
    this->m_window->draw(this->m_sprite);
}

sf::Vector2f Power::getPosition()
{
    return this->m_sprite.getPosition();
}




#include "Hamster.h"


Threat::Threat(sf::RenderWindow* window,sf::Texture& texture)
{
    this->m_window = window;

    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    this->m_sprite.setRotation(180);

    float x = std::rand() % 250 + 25;
    float y = std::rand() % 10;
    this->m_sprite.setPosition(x, -y);
    //std::cout << m_sprite.getPosition().y << "\n";
}

void Threat::update()
{
    this->m_sprite.move(0, 5);
}

void Threat::draw()
{
    this->m_window->draw(this->m_sprite);
}

sf::Vector2f Threat::getPosition()
{

    return this->m_sprite.getPosition();
}

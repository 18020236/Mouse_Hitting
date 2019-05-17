#include "Hammer.h"

Hammer::Hammer(sf::RenderWindow* window)
{
    this->m_window = window;
    this->m_window->setMouseCursorVisible(false);

    this->m_texture_hammer.loadFromFile("Assets/Texture/hammer.png");
    this->m_texture_hammer.setSmooth(true);
    this->m_sprite_hammer.scale(0.36, 0.36);
    this->m_sprite_hammer.setOrigin(this->m_texture_hammer.getSize().x / 2, this->m_texture_hammer.getSize().y / 2);

    this->m_sprite_hammer.setTexture(this->m_texture_hammer);
}

void Hammer::update()
{
    sf::Vector2i hammer_position = sf::Mouse::getPosition(*this->m_window);

    if (hammer_position.x <= 60)
        hammer_position.x = 60;
    if (hammer_position.x >= 1750)
        hammer_position.x = 1750;

    if (hammer_position.y <= 50)
        hammer_position.y = 50;
    if (hammer_position.y >= 900)
        hammer_position.y = 900;
    this->m_sprite_hammer.setPosition(hammer_position.x, hammer_position.y);
}
void Hammer::draw()
{
    this->m_window->draw(this->m_sprite_hammer);
}

sf::Vector2f Hammer::getPosition()
{
    return this->m_sprite_hammer.getPosition();
}

#include "Threat.h"

Threat::Threat(sf::RenderWindow* window, sf::Texture& texture, float speed)
{
    sf::IntRect rectPlayer;
    this->m_window = window;
    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(850/2, 520/2);
    this->m_sprite.setScale(0.18, 0.18);
    this->m_speed = speed;

    this->m_Frame = 0;
    for (int i = 0; i < 12; i++)
        this->m_Frames.push_back(sf::IntRect(0 + 850*i, 0, 850, 520));

    float rand = std::rand() % 5;
    int pos = 122 + rand*180;
    this->m_sprite.setPosition(1809, pos);
}


void Threat::update(float speed)
{
    this->m_sprite.move(- speed, 0);
    this->m_Frame += 0.8;
    int n = this->m_Frames.size();
    if (this->m_Frame >= n)
        this->m_Frame -= n;
    this->m_sprite.setTextureRect(this->m_Frames[int(this->m_Frame)]);
}

void Threat::draw()
{
    this->m_window->draw(this->m_sprite);
}

sf::Vector2f Threat::getPosition()
{
    return this->m_sprite.getPosition();
}


#include "Boss_Threat.h"

Boss_Threat::Boss_Threat(sf::RenderWindow* window, sf::Texture& texture)
{

    sf::IntRect rectPlayer;
    this->m_window = window;
    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(850/2, 520/2);
    this->m_sprite.setScale(0.9, 0.9);
    this->m_Frame = 0;

    for (int i = 0; i < 12; i++)
        this->m_Frames.push_back(sf::IntRect(0 + 850*i, 0, 850, 520));

    float rand = std::rand() % 4;
    int pos = 190 + rand*180;
    this->m_sprite.setPosition(1809, pos);
}


void Boss_Threat::update(float speed)
{
    this->m_sprite.move(- speed, 0);
    this->m_Frame += 0.8;
    int n = this->m_Frames.size();
    if (this->m_Frame >= n)
        this->m_Frame -= n;
    this->m_sprite.setTextureRect(this->m_Frames[int(this->m_Frame)]);
}

void Boss_Threat::draw()
{
    this->m_window->draw(this->m_sprite);

}

sf::Vector2f Boss_Threat::getPosition()
{
    return this->m_sprite.getPosition();
}


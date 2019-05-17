//#include "moveAnimation.h"
//int x, y, m;
//moveAnimation::moveAnimation(sf::RenderWindow * window, sf::Texture &t, int column, int line, int width, int height, float speed, int frames, float scale, sf::Vector2f position, float sp)
//{
//    m = sp;
//    x = position.x;
//    y = position.y;
//	this->m_window = window;
//    this->m_speed = speed;
//    this->m_Frame = 0;
//
//    for (int i = 0; i < frames; i++)
//        this->m_Frames.push_back(sf::IntRect(column + width*i, line, width, height));
//    this->m_sprite.setTexture(t);
//    //this->m_sprite.setScale(0.2, 0.2);
//    this->m_sprite.setOrigin(width / 2, height / 2);
//    //this->m_sprite.setPosition(position.x, position.y);
//    this->m_sprite.scale(scale, scale);
//    this->m_sprite.setTextureRect(this->m_Frames[0]);
//}
//
//void moveAnimation::update()
//{
//    x -= m;
//	this->m_Frame += this->m_speed;
//    int n = this->m_Frames.size();
//    if (this->m_Frame > n)
//        this->m_Frame -= n;
//    this->m_sprite.setTextureRect(this->m_Frames[int(this->m_Frame)]);
//    this->m_sprite.setPosition(x , y);
//}
//
//void moveAnimation::draw()
//{
//	this->m_window->draw(this->m_sprite);
//}
//
//bool moveAnimation::checkEnd()
//{
//    if(this->m_Frame + this->m_speed >= this->m_Frames.size())
//        return true;
//    return false;
//}
//
//void moveAnimation::setPosition(int x, int y)
//{
//    this->m_sprite.setPosition(x, y);
//}
//

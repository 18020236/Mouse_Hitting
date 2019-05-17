#ifndef _Game_H_
#define _Game_H_

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include"Animation.h"
#include"Threat.h"
#include"Boss_Threat.h"
#include"Hammer.h"
#include"Power.h"
#include<moveAnimation.h>
#include<list>

class Game
{
private:
    sf::RenderWindow*           m_window;

    sf::Texture                 m_texture_background;

    std::vector<sf::Texture>    m_texture_boss_threat;
    std::vector<sf::Texture>    m_texture_threat;
    std::vector<sf::Texture>    m_texture_dis_animation;
    std::vector<sf::Texture>    m_texture_threat_animation;
    sf::Texture                 m_texture_hammer_animation;
    sf::Texture                 m_texture_power;

    sf::Sprite                  m_sprite_background;
    sf::Sprite                  m_sprite_power;

    sf::Clock                   m_clock;
    sf::Clock                   m_a_clock;

    sf::Time                    m_time;
    sf::Time                    m_a_time;

    sf::Text                    m_text;
    sf::Text                    m_text_score;
    sf::Text                    m_level_text;

    Hammer*                     m_hammer;

    std::string                 m_file_name[7];
    std::string                 m_dis_animation_file_name[7];
    std::string                 m_threat_animation_name[7];
    int                         m_score = 0;
    int                         m_count_threat = 0;
    int                         m_clear_time = 3;
    float                       m_speed = 4.5;

    std::list<Threat>           m_threat;
    std::list<Power>            m_power;
    std::list<Boss_Threat>      m_boss_threat;
    std::vector<int>            m_boss_life;
    std::list<Animation>        m_hammer_animation;
    std::list<Animation>        m_dis_animation;
    std::list<sf::Sound>        m_hammer_sounds;

    sf::SoundBuffer             m_hammer_buffer;
    sf::Sound                   m_hammer_sound;

    sf::SoundBuffer             m_die_buffer;
    sf::Sound                   m_die_sound;
    sf::Music                   m_music;
public:
    Game(sf::RenderWindow* window);

    sf::Font                    m_font;
    void                        update(int &play);
    void                        draw();
    void                        restart();
};

#endif


#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
    this->m_window = window;

    this->m_hammer = new Hammer(this->m_window);
    //background
    this->m_texture_background.loadFromFile("Assets/Texture/background1.png");
    this->m_texture_background.setSmooth(true);
    this->m_sprite_background.setTexture(this->m_texture_background);
    //clear icon
    this->m_texture_power.loadFromFile("Assets/Texture/power.png");
    this->m_texture_power.setSmooth(true);
    this->m_sprite_power.setTexture(this->m_texture_power);
    this->m_sprite_power.setScale(0.1, 0.1);

    //mouse image
    for(int i = 1; i <= 6; i++)
    {
        this->m_file_name[i] = "Assets/Texture/mouse";
        this->m_file_name[i] += char(i + 48);
        this->m_file_name[i] += ".png";
    }
    //mouse animation
    for(int i = 1; i <= 6; i++)
    {
        this->m_threat_animation_name[i] = "Assets/Texture/animation";
        this->m_threat_animation_name[i] += char(i + 48);
        this->m_threat_animation_name[i] += ".png";
    }

    this->m_texture_threat.resize(7);
    this->m_texture_boss_threat.resize(7);
    this->m_texture_threat_animation.resize(7);
    //load image
    for(int i = 1; i <= 6; i++){
        this->m_texture_threat[i].loadFromFile(this->m_threat_animation_name[i]);
        this->m_texture_threat[i].setSmooth(true);
    }

    for(int i = 1; i <= 6; i++){
        this->m_texture_boss_threat[i].loadFromFile(this->m_threat_animation_name[i]);
        this->m_texture_boss_threat[i].setSmooth(true);
    }

    for(int i = 1; i <= 6; i++){
        this->m_texture_threat_animation[i].loadFromFile(this->m_threat_animation_name[i]);
        this->m_texture_threat_animation[i].setSmooth(true);
    }

    this->m_texture_hammer_animation.loadFromFile("Assets/Texture/a_hammer.png");
    this->m_texture_hammer_animation.setSmooth(true);

    for(int i = 1; i <= 1; i++)
    {
        this->m_dis_animation_file_name[i] = "Assets/Texture/dis_animation";
        this->m_dis_animation_file_name[i] += char(i + 48);
        this->m_dis_animation_file_name[i] += ".png";
    }
    this->m_texture_dis_animation.resize(3);

    for(int i = 1; i <= 1; i++){
        this->m_texture_dis_animation[i].loadFromFile(this->m_dis_animation_file_name[i]);
        this->m_texture_threat[i].setSmooth(true);
    }
    //Score Text
    this->m_font.loadFromFile("Assets/font/Lato-Bold.ttf");
    //Score
    this->m_text_score.setFont(this->m_font);
    this->m_text_score.setCharacterSize(72);
    this->m_text_score.setFillColor(sf::Color(0, 255, 153));
    this->m_text_score.setPosition(154, 0);
    char a[6];
    //Sound
    this->m_hammer_buffer.loadFromFile("Assets/sound/hit2.wav");
    this->m_hammer_sound.setBuffer(this->m_hammer_buffer);

    this->m_die_buffer.loadFromFile("Assets/sound/die2.wav");
    this->m_die_sound.setBuffer(this->m_die_buffer);

    this->m_music.openFromFile("Assets/sound/music.wav");
    this->m_music.setLoop(true);
    this->m_music.play();
}

void Game::update(int &play)
{
    this->m_hammer->update();

    if(this->m_threat.size() > 0)
    {
        for(std::list<Threat>::iterator it = this->m_threat.begin();
            it != this->m_threat.end(); it++)
        {
            it->update(this->m_speed);
        }
    }

    if(this->m_power.size() > 0)
    {
        for(std::list<Power>::iterator it = this->m_power.begin();
            it != this->m_power.end(); it++)
        {
            it->update(this->m_speed);
        }
    }

    if(this->m_boss_threat.size() > 0)
    {
        for(std::list<Boss_Threat>::iterator it = this->m_boss_threat.begin();
            it != this->m_boss_threat.end(); it++)
        {
            it->update(this->m_speed);
        }
    }

    this->m_a_time = this->m_a_clock.getElapsedTime();

    if(this->m_a_time.asSeconds() > 0.07){
        //after click
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->m_hammer_sound.play();
            std::cout << "click\n";
            this->m_hammer_animation.push_back(Animation(this->m_window, this->m_texture_hammer_animation, 0, 0, 340, 450, 2, 21, 0.36,
                                                sf::Vector2f(this->m_hammer->getPosition().x, this->m_hammer->getPosition().y)));

        }

        if(this->m_threat.size() > 0)
        {
            if(this->m_clear_time > 0    and    sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                for(std::list<Threat>::iterator it = m_threat.begin(); it!= m_threat.end(); it++){
                    this->m_hammer_animation.push_back(Animation(this->m_window, this->m_texture_hammer_animation, 0, 0, 340, 450, 2, 21, 0.36,
                                                    sf::Vector2f(it->getPosition().x, it->getPosition().y)));
                    this->m_dis_animation.push_back(Animation(this->m_window, this->m_texture_dis_animation[1], 0, 0, 315, 320, 0.5, 7, 0.36,
                                                    sf::Vector2f(it->getPosition().x - 30, it->getPosition().y)));
                    this->m_score += 10;
                }
                this->m_threat.clear();

                if(this->m_boss_threat.size() > 0)
                {
                    for(std::list<Boss_Threat>::iterator it = m_boss_threat.begin(); it!= m_boss_threat.end(); it++){
                    this->m_hammer_animation.push_back(Animation(this->m_window, this->m_texture_hammer_animation, 0, 0, 340, 450, 2, 21, 1.44,
                                                    sf::Vector2f(it->getPosition().x, it->getPosition().y)));
                    this->m_dis_animation.push_back(Animation(this->m_window, this->m_texture_dis_animation[1], 0, 0, 315, 320, 0.5, 7, 1.8,
                                                    sf::Vector2f(it->getPosition().x - 120, it->getPosition().y)));
                    this->m_score += 111;
                    }
                    this->m_boss_threat.clear();
                }

                this->m_clear_time--;
            }
        }

        int x_distance;
        int y_distance;

        if(this->m_threat.size() > 0)
        {
            for (std::list<Threat>::iterator it = this->m_threat.begin();
                                        it != this->m_threat.end(); it++)
            {
                //HIT THE HAMSTER
                x_distance = this->m_hammer->getPosition().x - it->getPosition().x;
                y_distance = this->m_hammer->getPosition().y - it->getPosition().y;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
                    && -76 <= x_distance && x_distance <= 60 && -80 <= y_distance && y_distance <= 47)
                {
                    this->m_dis_animation.push_back(Animation(this->m_window, this->m_texture_dis_animation[1], 0, 0, 315, 320, 0.5, 7, 0.36,
                                                sf::Vector2f(it->getPosition().x - 30, it->getPosition().y)));
                    this->m_threat.erase(it);
                    this->m_die_sound.play();

                    this->m_score += 10;
                    std:: cout << "Mouse is hit!!!\n";
                    std:: cout << "Score " << this->m_score << std::endl;
                    std:: cout << "Hamster: " << m_threat.size() << "\n";
                    std:: cout << "Speed " << this->m_speed * 10 << "km/h" << std::endl << std::endl;
                    std:: cout << "--------------" << 1 - float(this->m_count_threat) / 300;
                    break;
                }

                //LOSE
                if(it->getPosition().x < 108)
                {
                    //Notify Score and The amount of hamster
                    char a[6];
                    std::string content = "Score: " + std::string(itoa(this->m_score, a, 10))
                                            + "\nHamster: " + std::string(itoa(this->m_count_threat, a, 10));
                    if (MessageBox(NULL, content.c_str(), "Lose huhu", MB_OK) == IDOK);
                    //Back to the menu
                    play = 0;
                }
            }
        }

        if(this->m_boss_threat.size() > 0)
        {
            for (std::list<Boss_Threat>::iterator it = this->m_boss_threat.begin();
                                        it != this->m_boss_threat.end(); it++)
            {
                //HIT THE HAMSTER
                x_distance = this->m_hammer->getPosition().x - it->getPosition().x;
                y_distance = this->m_hammer->getPosition().y - it->getPosition().y;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
                    && -382 <= x_distance && x_distance <= 200 && -234 <= y_distance && y_distance <= 234)
                {
                    if(it->boss_life == 1){
                        this->m_score += 111;

                        this->m_hammer_animation.push_back(Animation(this->m_window, this->m_texture_hammer_animation, 0, 0, 340, 450, 2, 21, 1.44,
                                                    sf::Vector2f(it->getPosition().x, it->getPosition().y)));
                        this->m_dis_animation.push_back(Animation(this->m_window, this->m_texture_dis_animation[1], 0, 0, 315, 320, 0.5, 7, 1.8,
                                                    sf::Vector2f(it->getPosition().x - 120, it->getPosition().y)));
                        this->m_boss_threat.erase(it);
                        this->m_die_sound.play();
                        std:: cout << "That's a Hamster Killer!!!\n";
                        std:: cout << "Boss is killed" << std::endl;
                        std:: cout << "Score " << this->m_score << std::endl;
                        std:: cout << "Boss Hamster: " << m_boss_threat.size() << std::endl;
                        std:: cout << "Speed " << this->m_speed * 100 << "km/h" << std::endl << std::endl;
                    }
                    it->boss_life--;
                    std:: cout << "Keep Clicking!!!\n";
                    std:: cout << "Boss_Life: " << it->boss_life << "\n";
                    std:: cout << "Score " << this->m_score << std::endl;
                    std:: cout << "Boss Hamster: " << m_boss_threat.size() << "\n";
                    std:: cout << "Speed " << this->m_speed * 10 << "km/h" << std::endl << std::endl;
                    break;
                }

                //LOSE
                if(it->getPosition().x < 288)
                {
                    char a[6];
                    std::string content = "Score: " + std::string(itoa(this->m_score, a, 10))
                                            + "\nHamster: " + std::string(itoa(this->m_count_threat, a, 10));
                    if (MessageBox(NULL, content.c_str(), "Lose huhu", MB_OK) == IDOK);
                    //Back to the menu
                    play = 0;
                }
            }
        }

        if(this->m_power.size() > 0)
        {
            for (std::list<Power>::iterator it = this->m_power.begin();
                                        it != this->m_power.end(); it++)
            {
                //Get the power
                x_distance = this->m_hammer->getPosition().x - it->getPosition().x;
                y_distance = this->m_hammer->getPosition().y - it->getPosition().y;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
                    && -61 <= x_distance && x_distance <= 61 && -81 <= y_distance && y_distance <= 81)
                {
                    this->m_power.erase(it);
                    this->m_die_sound.play();
                    m_clear_time++;
                    this->m_score += 10;
                    std:: cout << "Power!!!!!\n";
                    break;
                }
            }
        }
        this->m_a_clock.restart();
    }

    this->m_time = this->m_clock.getElapsedTime();
    //time := time to release a hamster
    float time = 1 - float(this->m_count_threat) / 300;
    if(time <= 0.15) time = 0.15;
    if (this->m_time.asSeconds() > time){
        this->m_count_threat++;
        switch (std::rand() % 7)
        {
        case 0:
        {
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat[1], this->m_speed));
            break;
        }
        case 1:
        {
            //release a hammer power
            int x = rand()%8;
            if(x == 0){
                this->m_power.push_back(Power(this->m_window, this->m_texture_power, this->m_speed));
            }
            else this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat[2], this->m_speed));
            break;
        }
        case 2:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat[3], this->m_speed));
            break;
        case 3:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat[4], this->m_speed));
            break;
        case 4:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat[5], this->m_speed));
            break;
        case 5:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat[6], this->m_speed));
            break;
        case 6:
            //release a boss hamster
            this->m_boss_threat.push_back(Boss_Threat(this->m_window, this->m_texture_boss_threat[rand() % 6 + 1]));
            this->m_boss_life.push_back(3);
            break;
        }
        this->m_clock.restart();
        if(this->m_count_threat % 10 == 1 and this->m_speed <= 17) this->m_speed += 0.5;
     }

    if (this->m_hammer_animation.size() > 0)
    {
        for (std::list<Animation>::iterator it = this->m_hammer_animation.begin();
         it != this->m_hammer_animation.end(); it++)
            it->update();
        if (this->m_hammer_animation.begin()->checkEnd())
            this->m_hammer_animation.pop_front();
    }

    if (this->m_dis_animation.size() > 0)
    {
        for (std::list<Animation>::iterator it = this->m_dis_animation.begin();
         it != this->m_dis_animation.end(); it++)
            it->update();
        if (this->m_dis_animation.begin()->checkEnd())
            this->m_dis_animation.pop_front();
    }

     //set score for text
     char a[6];
     this->m_text.setString("Ultimate: " + std::string(itoa(this->m_clear_time, a, 10)));
     this->m_text_score.setString("Score: " + std::string(itoa(this->m_score, a, 10)));

}
void Game::draw()
{
    this->m_window->draw(this->m_sprite_background);
    //hammer power icon
    for(int i = 0; i < m_clear_time; i++){
        this->m_sprite_power.setPosition(150 + i*40, 100);
        this->m_window->draw(this->m_sprite_power);
    }

    this->m_window->draw(this->m_text);
    this->m_window->draw(this->m_text_score);

    if (this->m_dis_animation.size() > 0)
    {
        for (std::list<Animation>::iterator it = this->m_dis_animation.begin(); it != this->m_dis_animation.end(); it++)
            it->draw();
    }

    if(this->m_threat.size() > 0)
    {
        for(std::list<Threat>::iterator it = this->m_threat.begin();
            it != this->m_threat.end(); it++)
        {
            it->draw();
        }
    }

    if(this->m_power.size() > 0)
    {
        for(std::list<Power>::iterator it = this->m_power.begin();
            it != this->m_power.end(); it++)
        {
            it->draw();
        }
    }

    if(this->m_boss_threat.size() > 0)
    {
        for(std::list<Boss_Threat>::iterator it = this->m_boss_threat.begin();
            it != this->m_boss_threat.end(); it++)
        {
            it->draw();
        }
    }

    this->m_hammer->draw();

    if (this->m_hammer_animation.size() > 0)
    {
        for (std::list<Animation>::iterator it = this->m_hammer_animation.begin(); it != this->m_hammer_animation.end(); it++)
            it->draw();

    }
}

void Game::restart(){
    m_clock.restart();
    m_a_clock.restart();

    m_score = 0;
    m_count_threat = 0;
    m_clear_time = 3;
    m_speed = 4.5;

    m_threat.clear();
    m_power.clear();
    m_boss_threat.clear();
    m_boss_life.clear();
    m_hammer_animation.clear();
    m_dis_animation.clear();
}

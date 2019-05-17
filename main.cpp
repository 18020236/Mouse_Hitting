#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>
#include"Game.h"
#include"Hammer.h"

int play = 0;

int main()

{
    sf::RenderWindow window(sf::VideoMode(1800, 943),"Mouse Hitting",sf::Style::Default);

    //FPS
    window.setFramerateLimit(60);

    sf::Image Icon;
    Icon.loadFromFile("Assets/Texture/icon.png");
    window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());

    std::srand(time(NULL));
    Game game(&window);
    bool checkChooseWindow = true;

    //Menu

    sf::Texture         texture_end1;
    sf::Sprite          sprite_end1;
    texture_end1.loadFromFile("Assets/Texture/start.png");
    sprite_end1.setTexture(texture_end1);

    //GAME LOOP
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::LostFocus)
                checkChooseWindow = false;
            if(event.type == sf::Event::GainedFocus)
                checkChooseWindow = true;
        }
        if(checkChooseWindow){
            window.clear();
            int x = sf::Mouse::getPosition().x;
            int y = sf::Mouse::getPosition().y;
            if(play == 0){
                window.draw(sprite_end1);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
//                    Game game(&window);
                    play = 2;
                }
            }
            else if(play == 1){
                game.update(play);
                game.draw();
            }
            else if(play == 2){
                game.restart();
                play = 1;
            }
            window.display();
        }
    }

    return EXIT_SUCCESS;
}

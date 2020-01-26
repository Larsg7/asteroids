// 
// Created by Adrian Valadkhani on 26.01.20.
//

#ifndef ASTEROIDS_MAINMENU_H
#define ASTEROIDS_MAINMENU_H

#include <SFML/Graphics/RenderWindow.hpp>

class Asteroids;

class MainMenu {
private:
    sf::RenderWindow* window;
    Asteroids* asteroids;
public:

    void update();
    void display();

    MainMenu(sf::RenderWindow *window, Asteroids *asteroids);

    MainMenu();

    void acceptInput(sf::Event &event);

    float startx;
    float starty;
    float exitx;
    float exity;
    float sWidth;
    float sHeight;
    float eWidth;
    float eHeight;
    int padding;
};


#endif //ASTEROIDS_MAINMENU_H

//
// Created by Lars Groeber on 24.01.20.
//

#ifndef ASTEROIDS_HUD_H
#define ASTEROIDS_HUD_H


#include <SFML/Graphics/RenderWindow.hpp>

class Hud {
public:
    Hud(sf::RenderWindow *window);

    void display();

    void setLives(unsigned lives);

    void setPoints(unsigned points);

private:
    unsigned lives;
    unsigned points;
    sf::RenderWindow* window;
};


#endif //ASTEROIDS_HUD_H

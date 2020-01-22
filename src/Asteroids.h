//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameState.h"
#include "Player.h"

class Asteroids {
private:
    GameState gameState = Menu;
    unsigned points;
    unsigned lives = 5;
    sf::RenderWindow* window;
    Player player;

    void advanceAsteroids();
public:
    void run();
    void acceptInput(sf::Event &event);

    Asteroids(sf::RenderWindow *window);
};


#endif //ASTEROIDS_ASTEROIDS_H

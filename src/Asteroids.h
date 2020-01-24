//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameState.h"
#include "Player.h"
#include "Asteroid.h"

class Asteroids {
private:
    GameState gameState = Menu;
    unsigned points = 0U;
    unsigned lives = 5U;
    sf::RenderWindow* window;
    Player player;
    Asteroid asteroid;

    void advanceAsteroids();
public:
    void run();
    void acceptInput(sf::Event &event);

    Asteroids(sf::RenderWindow *window);

    void handleKeyPress(sf::Event &event);
};


#endif //ASTEROIDS_ASTEROIDS_H

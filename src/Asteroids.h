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
#include "Bullet.h"

class Asteroids {
private:
    GameState gameState = Menu;
    unsigned points = 0U;
    unsigned lives = 5U;

    const float bulletSpeed = 10.f;

    sf::RenderWindow* window;
    Asteroid asteroid;
    Player* player;
    std::vector<Bullet> bullets;
    std::vector<MoveAble> asteroids; // TODO

    void advanceAsteroids();

    void shootBullet();

    void advanceBullets();

    void cleanUp();

    bool outsideWindow(MoveAble* iter);

public:
    void run();

    void acceptInput(sf::Event &event);

    Asteroids(sf::RenderWindow *window);

    void handleKeyPress(sf::Event &event);


    void handleMouseMove(sf::Event &event);

    void handleMousePressed(sf::Event &event);
};


#endif //ASTEROIDS_ASTEROIDS_H

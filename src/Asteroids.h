//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <stdlib.h>
#include "GameState.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "MoveAble.h"
#include "Hud.h"

class Asteroids {
public:
    virtual ~Asteroids();

    void run();

    void acceptInput(sf::Event &event);

    Asteroids(sf::RenderWindow *window);

    void handleKeyPress(sf::Event &event);

    void handleMouseMove(sf::Event &event);

    void handleMousePressed(sf::Event &event);

private:
    const unsigned startingLives = 5U;
    GameState gameState = Menu;
    unsigned points = 0U;
    unsigned lives = 5U;

    const float bulletSpeed = 10.f;

    sf::RenderWindow *window;
    Player *player;
    Hud *hud;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids; // TODO

    void advanceAsteroids();

    void shootBullet();

    void advanceBullets();

    void cleanUp();

    bool outsideWindow(MoveAble *iter);

    void updateHud() const;

    void updatePlayer() const;

    void checkCollisions();

    void checkPlayerAsteroidCollisions();

    void playerHit();

    sf::Vector2<float> getInitialPlayerPos() const;

    void checkBulletAsteroidCollisions();

    void checkForGameOver();

    void runGame();

    void resetGame();

    void resetPlayer() const;
};


#endif //ASTEROIDS_ASTEROIDS_H

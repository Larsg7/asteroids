//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdlib>
#include "GameState.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "MoveAble.h"
#include "Hud.h"
#include "MainMenu.h"
#include "GameO.h"

class Asteroids {
public:
    virtual ~Asteroids();

    void run();

    void acceptInput(sf::Event &event);

    Asteroids(sf::RenderWindow *window);

    void handleKeyPress(sf::Event &event);

    void handleMouseMove(sf::Event &event);

    void handleMousePressed(sf::Event &event);

    GameState gameState = Menu;
private:
    const unsigned startingLives = 5U;
    unsigned points = 0U;
    unsigned lives = 5U;

    const float bulletSpeed = 10.f;

    sf::RenderWindow *window;
    Player *player;
    Hud *hud;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
    std::chrono::time_point<std::chrono::high_resolution_clock> last_shot = std::chrono::high_resolution_clock::now();
    float timeBetweenShots = 0.2; // in seconds
    MainMenu* mMenu;
    GameO* gameO;

    void shootBullet();

    void cleanUp();

    bool outsideWindow(MoveAble *iter);

    void updateHud() const;

    void checkCollisions();

    void checkPlayerAsteroidCollisions();

    void playerHit();

    sf::Vector2<float> getInitialPlayerPos() const;

    void checkBulletAsteroidCollisions();

    void checkForGameOver();

    void runGame();

    void resetGame();

    void resetPlayer() const;

    void pauseGame();

    void update();

    void draw();
};


#endif //ASTEROIDS_ASTEROIDS_H

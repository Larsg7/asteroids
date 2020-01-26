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
#include "MainMenu.h"

class Asteroids {
private:
    GameState gameState = Menu;
    unsigned points = 0U;
    unsigned lives = 5U;

    const float bulletSpeed = 10.f;

    sf::RenderWindow* window;
    Player* player;
    Hud* hud;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
    MainMenu* mMenu;

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
    
    double nextRandom(double min, double max);

    void handleMousePressed(sf::Event &event);
};


#endif //ASTEROIDS_ASTEROIDS_H

//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H


#include "MoveAble.h"

class Player : MoveAble {
public:
    // these methods will be called on input events and change position or velocity
    void turnRight();
    void turnLeft();
    void moveForward();
    void moveBackward();

    void update() override;
    void draw(sf::RenderWindow *window) override;

    Player(const sf::Vector2f &position, const sf::Vector2f &velocity);

    Player();
};


#endif //ASTEROIDS_PLAYER_H

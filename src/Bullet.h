//
// Created by Lars Groeber on 24.01.20.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H


#include "MoveAble.h"

class Bullet : MoveAble {
    void draw(sf::RenderWindow *window) override;

    void update() override;
};


#endif //ASTEROIDS_BULLET_H

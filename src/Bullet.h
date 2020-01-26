//
// Created by Lars Groeber on 24.01.20.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H


#include "MoveAble.h"

class Bullet : public MoveAble {
public:
    constexpr const static float radius = 10.f;
    void draw(sf::RenderWindow *window) override;

    void update() override;
    Bullet(const sf::Vector2f &position, const sf::Vector2f &velocity, float rotation);

};


#endif //ASTEROIDS_BULLET_H

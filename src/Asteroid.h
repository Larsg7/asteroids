// 
// Created by Adrian Valadkhani on 24.01.20.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "MoveAble.h"

class Asteroid : MoveAble {
private:
    float speed = 1.f;
    float direction = 1;
public:

    void setVel();

    void update() override;
    void draw(sf::RenderWindow *window) override;

    Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity);
    
    Asteroid();
};


#endif //ASTEROIDS_ASTEROID_H

// 
// Created by Adrian Valadkhani on 24.01.20.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "MoveAble.h"

class Asteroid : public MoveAble {
private:
    float speed;
    float minSpeed=4;
    float maxSpeed=8;
    float minSize=10;
    float maxSize=70;
    float size;
    float direction;
public:

    void setVel();

    void update() override;
    void draw(sf::RenderWindow *window) override;
    
    sf::Vector2f startPos(float xlen, float ylen);

    Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity);
    
    Asteroid();
};


#endif //ASTEROIDS_ASTEROID_H

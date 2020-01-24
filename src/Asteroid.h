// 
// Created by Adrian Valadkhani on 24.01.20.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "MoveAble.h"

class Asteroid : MoveAble {
private:
    float speed;
    float minSpeed=1;
    float maxSpeed=10;
    float minSize=10;
    float maxSize=80;
    float size;
    float direction;
    int startDir;
public:

    void setVel();

    void update() override;
    void draw(sf::RenderWindow *window) override;
    
    sf::Vector2f startPos(float xlen, float ylen);

    Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity);
    
    Asteroid();
};


#endif //ASTEROIDS_ASTEROID_H

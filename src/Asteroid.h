// 
// Created by Adrian Valadkhani on 24.01.20.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "MoveAble.h"

class Asteroid : public MoveAble {
private:
// some variables to define the properties of an asteroid
    float speed;
    float minSpeed=4;
    float maxSpeed=8;
    float minSize=10;
    float maxSize=70;
    float radius;
    float direction;
public:
    // needed for collision
    float getRadius() const;

    // calculates the velocity using the direction
    void setVel();

    // update Asteroid
    void update() override;
    // draw Asteroid
    void draw(sf::RenderWindow *window) override;
    
    // generate starting position
    sf::Vector2f startPos(float xlen, float ylen);

    // constructor
    Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity);
    
    Asteroid();
};


#endif //ASTEROIDS_ASTEROID_H

//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_MOVEABLE_H
#define ASTEROIDS_MOVEABLE_H


#include <SFML/Graphics/RenderWindow.hpp>

class MoveAble {
protected:
    void updatePosition();
    virtual void draw(sf::RenderWindow *window) = 0;
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation;
    virtual void update() = 0;


    MoveAble(const sf::Vector2f &position, const sf::Vector2f &velocity, float rotation);

    MoveAble();
};


#endif //ASTEROIDS_MOVEABLE_H

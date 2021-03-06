//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_MOVEABLE_H
#define ASTEROIDS_MOVEABLE_H


#include <SFML/Graphics/RenderWindow.hpp>

class MoveAble {
protected:
    void updatePosition();
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation;
    virtual void update() = 0;

    const sf::Vector2f &getPosition() const;

    const sf::Vector2f &getVelocity() const;

    void setRotation(float rotation);

    float getRotation() const;
    sf::Vector2f getDirectionVector() const;
    virtual void draw(sf::RenderWindow *window) = 0;

    MoveAble(const sf::Vector2f &position, const sf::Vector2f &velocity, float rotation);

    MoveAble();

    virtual ~MoveAble();
};


#endif //ASTEROIDS_MOVEABLE_H

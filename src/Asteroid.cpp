// 
// Created by Adrian Valadkhani on 24.01.20.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Asteroid.h"
#include "Helper.h"

// calculating the velocity using the angle and speed
void Asteroid::setVel() {
    sf::Transform t;
    t.rotate(direction);
    velocity = t.transformPoint(sf::Vector2f(0, -1)) * speed;
}

// update the velocity and position of the Asteroid
void Asteroid::update() {
    setVel();
    updatePosition();
}

// draw the Asteroid
void Asteroid::draw(sf::RenderWindow *window) {
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Transparent);

    circle.setOutlineThickness(10.f);
    circle.setOutlineColor(sf::Color::White);
    circle.setOrigin(sf::Vector2f(radius, radius));
    circle.setPosition(position);
    window->draw(circle);
}

sf::Vector2f Asteroid::startPos(float xlen, float ylen) {
    float xstart, ystart;
    // randomize between 0 and 4
    int startDir = (int) Helper::nextRandom(0, 3.9);
    switch (startDir) {
        case 0:
            xstart = 0;//Top
            ystart = Helper::nextRandom(0, ylen);//random pos
            break;
        case 1:
            xstart = xlen;//Bottom
            ystart = Helper::nextRandom(0, ylen);//random pos
            break;
        case 2:
            ystart = 0;//Left
            xstart = Helper::nextRandom(0, xlen);//random pos
            break;
        case 3:
            ystart = ylen;//Right
            xstart = Helper::nextRandom(0, xlen);//random pos
            break;
        default:
            break;
    }
    return sf::Vector2f(xstart, ystart);
}

Asteroid::Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity) : MoveAble(position, velocity, 0) {
    speed = Helper::nextRandom(minSpeed, maxSpeed);// random speed
    sf::Vector2f endPos = sf::Vector2f(Helper::nextRandom(500, 1600), Helper::nextRandom(500, 1100));//random endposition
    direction = Helper::angleOfVector(sf::Vector2f(endPos.x - position.x, endPos.y - position.y)) + 180;//use position and end position to calculate direction
    radius = Helper::nextRandom(minSize, maxSize);// randomize size of asteroid
}

Asteroid::Asteroid() {}

// get the radius (needed for collision);
float Asteroid::getRadius() const {
    return radius;
}


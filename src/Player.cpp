//
// Created by Lars Groeber on 22.01.20.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

void Player::turnRight() {
    rotation += turnAngle;
}

void Player::turnLeft() {
    rotation -= turnAngle;
}

void Player::moveForward() {
    sf::Vector2f acc = getAccelerationVector();

    velocity += acc;
}

void Player::moveBackward() {
    sf::Vector2f acc = getAccelerationVector();

    velocity -= acc;
}

sf::Vector2f Player::getAccelerationVector() const {
    sf::Transform t;
    t.rotate(rotation);
    sf::Vector2f acc = t.transformPoint(sf::Vector2f(0, -1)) * acceleration;
    return acc;
}

void Player::update() {
    updatePosition();
}

void Player::draw(sf::RenderWindow *window) {
    sf::CircleShape triangle(80.f, 3);
    triangle.setFillColor(sf::Color::Black);

    triangle.setOutlineThickness(10.f);
    triangle.setOutlineColor(sf::Color::White);
    triangle.setOrigin(sf::Vector2f(80, 80));
    triangle.setPosition(position);
    triangle.setRotation(rotation);
    window->draw(triangle);
}

Player::Player(const sf::Vector2f &position, const sf::Vector2f &velocity) : MoveAble(position, velocity,
                                                                                      0) {}

Player::Player() {}


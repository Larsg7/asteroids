//
// Created by Lars Groeber on 22.01.20.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"
#include "Helper.h"

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
    return getDirectionVector() * acceleration;
}

void Player::update() {
    updatePosition();
    velocity = velocity * 0.999f;
}

void Player::draw(sf::RenderWindow *window) {
    maybeLoopPlayerPosition(window);
    sf::CircleShape triangle(radius, 3);
    sf::CircleShape tip(5, 100);
    triangle.setFillColor(sf::Color::Black);
    triangle.setOutlineThickness(10.f);
    triangle.setOutlineColor(sf::Color::White);
    triangle.setOrigin(sf::Vector2f(radius, radius));
    tip.setFillColor(sf::Color::Black);
    tip.setOutlineThickness(12.f);
    tip.setOutlineColor(sf::Color::White);
    tip.setOrigin(sf::Vector2f(5, 5));
    tip.setPosition(getTip() + getDirectionVector());
    triangle.setPosition(position);
    triangle.setRotation(rotation);
    window->draw(triangle);
    window->draw(tip);
}

Player::Player(const sf::Vector2f &position, const sf::Vector2f &velocity) : MoveAble(position, velocity,
                                                                                      0) {
    loadSounds();
}

Player::Player() = default;

sf::Vector2f Player::getTip() {
    return position + getDirectionVector() * radius;
}

void Player::maybeLoopPlayerPosition(sf::RenderWindow *window) {
    if (position.x < 0) {
        position.x = window->getSize().x;
    }
    if (position.x > window->getSize().x) {
        position.x = 0;
    }
    if (position.y < 0) {
        position.y = window->getSize().y;
    }
    if (position.y > window->getSize().y) {
        position.y = 0;
    }
}

void Player::loadSounds() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/shoot.wav"))
        return;
    shootingSound.setBuffer(buffer);
}

void Player::playShootingSound() {
    shootingSound.play();
}


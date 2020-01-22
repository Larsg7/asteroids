//
// Created by Lars Groeber on 22.01.20.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

void Player::turnRight() {

}

void Player::turnLeft() {

}

void Player::moveForward() {

}

void Player::moveBackward() {

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
    window->draw(triangle);
}

Player::Player(const sf::Vector2f &position, const sf::Vector2f &velocity) : MoveAble(position, velocity) {}

Player::Player() {}


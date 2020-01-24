//
// Created by Lars Groeber on 24.01.20.
//

#include <SFML/Graphics/CircleShape.hpp>
#include "Bullet.h"

void Bullet::draw(sf::RenderWindow *window) {
    sf::CircleShape shape(radius, 100);
    shape.setFillColor(sf::Color::Black);

    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color::White);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(position);
    shape.setRotation(rotation);
    window->draw(shape);
}

void Bullet::update() {
    updatePosition();
}

Bullet::Bullet(const sf::Vector2f &position, const sf::Vector2f &velocity, float rotation) : MoveAble(position,
                                                                                                      velocity,
                                                                                                      rotation) {}

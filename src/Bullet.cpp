//
// Created by Lars Groeber on 24.01.20.
//

#include <SFML/Graphics/CircleShape.hpp>
#include "Bullet.h"

void Bullet::draw(sf::RenderWindow *window) {
    sf::CircleShape shape(10.f, 100);
    shape.setFillColor(sf::Color::Black);

    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color::White);
    shape.setOrigin(sf::Vector2f(80, 80));
    shape.setPosition(position);
    shape.setRotation(rotation);
    window->draw(shape);
}

void Bullet::update() {
    updatePosition();
}

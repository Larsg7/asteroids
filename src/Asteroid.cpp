// 
// Created by Adrian Valadkhani on 24.01.20.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Asteroid.h"

void Asteroid::setVel() {
   sf::Transform t;
   t.rotate(direction);
   velocity = t.transformPoint(sf::Vector2f(0,-1)) * speed;
}

void Asteroid::update() {
   setVel();
   updatePosition();
}

void Asteroid::draw(sf::RenderWindow *window) {
   sf::CircleShape circle(80.f);
   circle.setFillColor(sf::Color::Transparent);

   circle.setOutlineThickness(10.f);
   circle.setOutlineColor(sf::Color::White);
   circle.setOrigin(sf::Vector2f(80,80));
   circle.setPosition(position);
   window->draw(circle);
}

Asteroid::Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity) : MoveAble(position,velocity,0) {}

Asteroid::Asteroid(){}


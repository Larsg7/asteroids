//
// Created by Lars Groeber on 22.01.20.
//

#include "Asteroids.h"

void Asteroids::run() {
    player.draw(window);
}

void Asteroids::acceptInput(sf::Event &event) {

}

void Asteroids::advanceAsteroids() {

}

Asteroids::Asteroids(sf::RenderWindow *window) : window(window) {
    player = Player(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2), sf::Vector2f());
}


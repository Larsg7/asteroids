//
// Created by Lars Groeber on 22.01.20.
//

#include "Asteroids.h"

void Asteroids::run() {
    player.draw(window);
    player.update();
    advanceAsteroids();
}

void Asteroids::acceptInput(sf::Event &event) {
    switch (event.type) {
        // key pressed
        case sf::Event::KeyPressed:
            handleKeyPress(event);
            break;
        default:
            break;
    }
}

void Asteroids::advanceAsteroids() {

}

Asteroids::Asteroids(sf::RenderWindow *window) : window(window) {
    player = Player(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2), sf::Vector2f());
}

void Asteroids::handleKeyPress(sf::Event &event) {
    switch (event.key.code) {
        case sf::Keyboard::Left:
        case sf::Keyboard::A:
            player.turnLeft();
            break;
        case sf::Keyboard::Right:
        case sf::Keyboard::D:
            player.turnRight();
            break;
        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            player.moveForward();
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            player.moveBackward();
            break;
        default:
            break;
    }
}


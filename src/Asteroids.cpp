//
// Created by Lars Groeber on 22.01.20.
//

#include "Asteroids.h"
#include "Helper.h"

void Asteroids::run() {
    player->draw(window);
    player->update();
    advanceAsteroids();
    advanceBullets();
    cleanUp();
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
    player = new Player(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2), sf::Vector2f());
}

void Asteroids::handleKeyPress(sf::Event &event) {
    switch (event.key.code) {
        case sf::Keyboard::Left:
        case sf::Keyboard::A:
            player->turnLeft();
            break;
        case sf::Keyboard::Right:
        case sf::Keyboard::D:
            player->turnRight();
            break;
        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            player->moveForward();
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            player->moveBackward();
            break;
        case sf::Keyboard::Space:
        case sf::Keyboard::Enter:
            shootBullet();
            break;
        default:
            break;
    }
}

void Asteroids::shootBullet() {
    sf::Vector2f tip = player->getTip();
    sf::Vector2f velocity = player->getDirectionVector() * bulletSpeed;
    Bullet b(tip, velocity, 0);
    bullets.push_back(b);
}

void Asteroids::advanceBullets() {
    for (Bullet &b : bullets) {
        b.update();
        b.draw(window);
    }
}

void Asteroids::cleanUp() {
    for (auto it = bullets.begin(); it != bullets.end(); it++) {
        if (outsideWindow(it)) {
            bullets.erase(it--);
        }
    }
}

bool Asteroids::outsideWindow(std::vector<MoveAble, std::allocator<MoveAble>>::iterator iter) {
    int screenWidth = window->getSize().x;
    int screenHeight = window->getSize().y;

    sf::Vector2f pos = iter->position;
    return pos.x > screenWidth || pos.x < 0 || pos.y > screenHeight || pos.y < 0;
}



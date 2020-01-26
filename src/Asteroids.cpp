//
// Created by Lars Groeber on 22.01.20.
//

#include <iostream>
#include "Asteroids.h"
#include "Helper.h"

const int numAsteroids = 10;

void Asteroids::run() {
    switch (gameState) {
        case Menu:
            gameState = Starting; // TODO
            break;
        case Starting:
            resetGame();
            gameState = Running;
            break;
        case Running:
            runGame();
            break;
        case Pause:
            break;
        case GameOver:
            std::cout << "GAMEOVER" << std::endl;
            exit(0); // TODO
        case Quitting:
            break;
    }
}

void Asteroids::runGame() {
    updatePlayer();
    advanceAsteroids();
    advanceBullets();
    checkCollisions();
    checkForGameOver();
    cleanUp();
    updateHud();
}

void Asteroids::updatePlayer() const {
    player->draw(window);
    player->update();
}

void Asteroids::updateHud() const {
    hud->setLives(lives);
    hud->setPoints(points);
    hud->display();
}

void Asteroids::acceptInput(sf::Event &event) {
    switch (event.type) {
        // key pressed
        case sf::Event::KeyPressed:
            handleKeyPress(event);
            break;
        case sf::Event::MouseMoved:
            handleMouseMove(event);
            break;
        case sf::Event::MouseButtonPressed:
            handleMousePressed(event);
            break;
        default:
            break;
    }
}

void Asteroids::advanceAsteroids() {
    int numNewAst = numAsteroids - asteroids.size();
    for (int i = 0; i < numNewAst; i++) {
        Asteroid a(a.startPos(window->getSize().x, window->getSize().y), sf::Vector2f());
        asteroids.push_back(a);
    }
    for (Asteroid &m : asteroids) {
        m.update();
        m.draw(window);
    }
}

Asteroids::Asteroids(sf::RenderWindow *window) : window(window) {
    for (int i = 0; i < numAsteroids + 1; i++) {
        Asteroid a(a.startPos(window->getSize().x, window->getSize().y), sf::Vector2f());
        asteroids.push_back(a);
    }
    player = new Player(getInitialPlayerPos(), sf::Vector2f());
    hud = new Hud(window);
}

sf::Vector2<float>
Asteroids::getInitialPlayerPos() const { return sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2); }

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
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = now - last_shot;
    if ((difference).count() < timeBetweenShots) {
        return;
    }
    last_shot = std::chrono::high_resolution_clock::now();

    sf::Vector2f tip = player->getTip();
    sf::Vector2f velocity = player->getDirectionVector() * bulletSpeed;
    Bullet b(tip, velocity, 0);
    bullets.push_back(b);
    player->playShootingSound();
}

void Asteroids::advanceBullets() {
    for (Bullet &b : bullets) {
        b.update();
        b.draw(window);
    }
}

void Asteroids::cleanUp() {
    for (auto it = bullets.begin(); it != bullets.end(); it++) {
        if (outsideWindow(&(*it))) {
            bullets.erase(it--);
        }
    }
    for (auto it = asteroids.begin(); it != asteroids.end(); it++) {
        if (outsideWindow(&(*it))) {
            asteroids.erase(it--);
        }
    }
}

bool Asteroids::outsideWindow(MoveAble *iter) {
    int screenWidth = window->getSize().x;
    int screenHeight = window->getSize().y;

    sf::Vector2f pos = iter->position;
    return pos.x > screenWidth || pos.x < 0 || pos.y > screenHeight || pos.y < 0;
}

void Asteroids::handleMouseMove(sf::Event &event) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));

    sf::Vector2f distance = player->getPosition() - mousePos;

    float rotation = Helper::angleOfVector(distance);
    player->setRotation(rotation);
}

void Asteroids::handleMousePressed(sf::Event &event) {
    switch (event.mouseButton.button) {
        case sf::Mouse::Left:
            shootBullet();
            break;
        default:
            break;
    }
}

Asteroids::~Asteroids() {
    delete (player);
    delete (hud);
}

void Asteroids::checkCollisions() {
    checkPlayerAsteroidCollisions();
    checkBulletAsteroidCollisions();
}

void Asteroids::checkPlayerAsteroidCollisions() {
    for (auto it = asteroids.begin(); it != asteroids.end(); it++) {
        if (Helper::getLengthOfVector(it->getPosition() - player->getPosition()) < it->getRadius() + player->radius) {
            asteroids.erase(it--);
            playerHit();
        }
    }
}

void Asteroids::playerHit() {
    lives--;
    resetPlayer();
}

void Asteroids::resetPlayer() const {
    player->position = getInitialPlayerPos();
    player->velocity = sf::Vector2f();
}

void Asteroids::checkBulletAsteroidCollisions() {
    for (auto itAsteroids = asteroids.begin(); itAsteroids != asteroids.end(); itAsteroids++) {
        for (auto itBullets = bullets.begin(); itBullets != bullets.end(); itBullets++) {
            if (Helper::getLengthOfVector(itAsteroids->getPosition() - itBullets->getPosition()) <
                itAsteroids->getRadius() + itBullets->radius) {
                asteroids.erase(itAsteroids--);
                bullets.erase(itBullets--);
                points++;
            }
        }
    }
}

void Asteroids::checkForGameOver() {
    if (lives <= 0) {
        gameState = GameOver;
    }
}

void Asteroids::resetGame() {
    resetPlayer();
    lives = startingLives;
}


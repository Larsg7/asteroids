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
            mMenu->display();
            break;
        case Starting:
            resetGame();
            gameState = Running;
            break;
        case Running:
            runGame();
            break;
        case Pause:
            draw();
            updateHud();
            break;
        case GameOver:
            gameO->display(points);
            break;
        case Quitting:
            window->close();
            break;
    }
}

void Asteroids::runGame() {
    update();
    draw();
    checkCollisions();
    checkForGameOver();
    cleanUp();
    updateHud();
}

void Asteroids::updateHud() const {
    hud->setLives(lives);
    hud->setPoints(points);
    hud->display();
}

void Asteroids::acceptInput(sf::Event &event) {
    if (gameState == Menu) {
        mMenu->acceptInput(event);
        return;
    }
    if (gameState == GameOver) {
        gameO->acceptInput(event);
        return;
    }
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

Asteroids::Asteroids(sf::RenderWindow *window) : window(window) {
    for (int i = 0; i < numAsteroids + 1; i++) {
        Asteroid a(a.startPos(window->getSize().x, window->getSize().y), sf::Vector2f());
        asteroids.push_back(a);
    }
    player = new Player(getInitialPlayerPos(), sf::Vector2f());
    hud = new Hud(window);
    mMenu = new MainMenu(window, this);
    gameO = new GameO(window, this);
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
        case sf::Keyboard::Escape:
            pauseGame();
            break;
        default:
            break;
    }
}

void Asteroids::shootBullet() {
    if (gameState != Running) {
        return;
    }
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

void Asteroids::pauseGame() {
    if (gameState == Pause) {
        gameState = Running;
    } else {
        gameState = Pause;
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
    delete (mMenu);
    delete (gameO);
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
            float minDistance = itAsteroids->getRadius() + itBullets->radius;
            float distance = Helper::getLengthOfVector(itAsteroids->getPosition() - itBullets->getPosition());
            if (distance < minDistance) {
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

void Asteroids::update() {
    player->update();
    for (Asteroid &a: asteroids) {
        a.update();
    }
    for (Bullet &b: bullets) {
        b.update();
    }
    int numNewAst = numAsteroids - asteroids.size();
    for (int i = 0; i < numNewAst; i++) {
        Asteroid a(a.startPos(window->getSize().x, window->getSize().y), sf::Vector2f());
        asteroids.push_back(a);
    }
}

void Asteroids::draw() {
    player->draw(window);
    for (Asteroid &a: asteroids) {
        a.draw(window);
    }
    for (Bullet &b: bullets) {
        b.draw(window);
    }
}


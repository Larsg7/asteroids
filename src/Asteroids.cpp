//
// Created by Lars Groeber on 22.01.20.
//

#include "Asteroids.h"
#include "Helper.h"

const int numAsteroids = 10;

void Asteroids::run() {
    switch(gameState){
        case Menu:
	    menu->draw();
	    break;
	case Running:
            player->draw(window);
            player->update();
            advanceAsteroids();
            advanceBullets();
            cleanUp();
            hud->setLives(lives);
            hud->setPoints(points);
            hud->display();
	    break;
	default:
	    break;
    }
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
    int numNewAst=numAsteroids-asteroids.size();
    for (int i=0;i<numNewAst;i++){
        Asteroid a(a.startPos(window->getSize().x,window->getSize().y), sf::Vector2f());
	asteroids.push_back(a);
    }
    for (Asteroid &m : asteroids) {
        m.update();
        m.draw(window);
    }
}

Asteroids::Asteroids(sf::RenderWindow *window) : window(window) {
    for (int i=0;i<numAsteroids+1;i++){
        Asteroid a(a.startPos(window->getSize().x,window->getSize().y), sf::Vector2f());
	asteroids.push_back(a);
    }
    player = new Player(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2), sf::Vector2f());
    hud = new Hud(window);
    menu = new Menu(window);
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

bool Asteroids::outsideWindow(MoveAble* iter) {
    int screenWidth = window->getSize().x;
    int screenHeight = window->getSize().y;

    sf::Vector2f pos = iter->position;
    return pos.x > screenWidth || pos.x < 0 || pos.y > screenHeight || pos.y < 0;
}

void Asteroids::handleMouseMove(sf::Event &event) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));

    sf::Vector2f distance =  player->getPosition() - mousePos;

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


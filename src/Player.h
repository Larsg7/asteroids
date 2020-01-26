//
// Created by Lars Groeber on 22.01.20.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H


#include "MoveAble.h"
#include <SFML/Audio.hpp>

class Player : public MoveAble {
private:
    const float turnAngle = 5;
    const float acceleration = 0.1f;
    const float maxSpeed = 0.1f;
    sf::Vector2f getAccelerationVector() const;
    sf::Sound shootingSound;
public:
    const float radius = 40.f;
    // these methods will be called on input events and change position or velocity
    void turnRight();
    void turnLeft();
    void moveForward();
    void moveBackward();

    void update() override;
    void draw(sf::RenderWindow *window) override;

    Player(const sf::Vector2f &position, const sf::Vector2f &velocity);

    Player();


    sf::Vector2f getTip();

    void maybeLoopPlayerPosition(sf::RenderWindow *pWindow);

    void loadSounds();

    void playShootingSound();
};


#endif //ASTEROIDS_PLAYER_H

//
// Created by Lars Groeber on 22.01.20.
//

#include "MoveAble.h"

MoveAble::MoveAble(const sf::Vector2f &position, const sf::Vector2f &velocity) : position(position), velocity(velocity) {}

void MoveAble::updatePosition() {
    position = position + velocity;
}

MoveAble::MoveAble() {}

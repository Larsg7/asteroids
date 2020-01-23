//
// Created by Lars Groeber on 22.01.20.
//

#include "MoveAble.h"


void MoveAble::updatePosition() {
    position = position + velocity;
}

MoveAble::MoveAble() {}

MoveAble::MoveAble(const sf::Vector2f &position, const sf::Vector2f &velocity, float rotation) : position(position),
                                                                                                 velocity(velocity),
                                                                                                 rotation(rotation) {}


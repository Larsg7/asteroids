//
// Created by Lars Groeber on 22.01.20.
//

#include "MoveAble.h"
#include "Helper.h"


void MoveAble::updatePosition() {
    position = position + velocity;
}

MoveAble::MoveAble() {}

MoveAble::MoveAble(const sf::Vector2f &position, const sf::Vector2f &velocity, float rotation) : position(position),
                                                                                                 velocity(velocity),
                                                                                                 rotation(rotation) {}

const sf::Vector2f &MoveAble::getPosition() const {
    return position;
}

const sf::Vector2f &MoveAble::getVelocity() const {
    return velocity;
}

float MoveAble::getRotation() const {
    return rotation;
}

MoveAble::~MoveAble() {

}

sf::Vector2f MoveAble::getDirectionVector() const {
    return Helper::getUnitVector(rotation);
}


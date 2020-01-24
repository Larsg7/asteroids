//
// Created by Lars Groeber on 24.01.20.
//

#ifndef ASTEROIDS_HELPER_H
#define ASTEROIDS_HELPER_H


#include <SFML/Graphics/Transform.hpp>

class Helper {
public:
    static sf::Vector2f getUnitVector(float rotation) {
        sf::Transform t;
        t.rotate(rotation);
        return t.transformPoint(sf::Vector2f(0, -1));
    }
};


#endif //ASTEROIDS_HELPER_H

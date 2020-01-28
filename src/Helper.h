//
// Created by Lars Groeber on 24.01.20.
//

#ifndef ASTEROIDS_HELPER_H
#define ASTEROIDS_HELPER_H


#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <cmath>

class Helper {
public:
    static sf::Vector2f getUnitVector(float rotation) {
        sf::Transform t;
        t.rotate(rotation);
        return t.transformPoint(sf::Vector2f(0, -1));
    }

// a function to randomize float numbers; also use for int if you cast to (int) again
    static float nextRandom(float min, float max) {
        static bool firstTime = true;
        if (firstTime) { // as taught in the lecture srand only once using static bool 
            srand((unsigned) time(NULL));
            firstTime = false;
        }
        return (max - min) * (rand() / (float) RAND_MAX) + min;
    }

//
    static float angleOfVector(sf::Vector2f vector) {
        float x = vector.x;
        float y = vector.y;
        if (x == 0) // special cases
            return (y > 0) ? 90
                           : (y == 0) ? 0
                                      : 270;
        else if (y == 0) // special cases
            return (x >= 0) ? 0
                            : 180;
        int ret = atanf((float) y / x) / (M_PI) * 180;
        if (x < 0 && y < 0) // quadrant 
            ret = 180 + ret;
        else if (x < 0) // quadrant 
            ret = 180 + ret; // it actually substracts
        else if (y < 0) // quadrant 
            ret = 270 + (90 + ret); // it actually substracts
        return ret - 90;
    }

    static float getLengthOfVector(sf::Vector2<float> vector2) {
        return sqrt(pow(vector2.x, 2) + pow(vector2.y, 2));
    }

    static sf::Vector2i Mouse_Click() {
        static bool pressed = false;
        sf::Vector2i position;
        while (true) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (!pressed) {
                    position = sf::Mouse::getPosition();
                    pressed = true;
                    break;
                }
            } else {
                pressed = false;
            }
        }
        return position;
    }
};


#endif //ASTEROIDS_HELPER_H

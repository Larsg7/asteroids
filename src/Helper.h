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
    static float nextRandom(float min, float max){
        static bool firstTime = true;
	if (firstTime) {
	    srand( (unsigned)time(NULL));
	    firstTime = false;
	}
	return (max-min)*(rand()/(float)RAND_MAX)+min;
    }
};


#endif //ASTEROIDS_HELPER_H

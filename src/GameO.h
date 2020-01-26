// 
// Created by Adrian Valadkhani on 26.01.20.
//

#ifndef ASTEROIDS_GAMEO_H
#define ASTEROIDS_GAMEO_H

#include <SFML/Graphics/RenderWindow.hpp>

class GameO {
private:
    sf::RenderWindow* window;
public:

    void update();
    bool display(int npoints);
    
    GameO(sf::RenderWindow* window);
    
    GameO();
};


#endif //ASTEROIDS_GAMEO_H

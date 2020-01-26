// 
// Created by Adrian Valadkhani on 26.01.20.
//

#ifndef ASTEROIDS_GAMEO_H
#define ASTEROIDS_GAMEO_H

#include <SFML/Graphics/RenderWindow.hpp>

class Asteroids;

class GameO {
private:
    sf::RenderWindow* window;
    Asteroids* asteroids;
public:

    void update();
    void display(int npoints);
    
    GameO(sf::RenderWindow* window, Asteroids* asteroids);
    
    GameO();
    void acceptInput(sf::Event &event);

    float eWidth;
    float eHeight;
    float exitx;
    float exity;
    int padding2;
    float gWidth;
    float gHeight;
    float gox;
    int goy;
    int starty;
    int padding;
    float sWidth;
    float sHeight;
    float startx;
};


#endif //ASTEROIDS_GAMEO_H

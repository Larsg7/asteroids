// 
// Created by Adrian Valadkhani on 26.01.20.
//

#ifndef ASTEROIDS_GAMEO_H
#define ASTEROIDS_GAMEO_H

#include <SFML/Graphics/RenderWindow.hpp>

// predefine to prevent compile error
class Asteroids;

// some useful variables and function to define graphical user interface for the game over screen
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

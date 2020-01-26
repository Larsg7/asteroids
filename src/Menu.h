// 
// Created by Adrian Valadkhani on 26.01.20.
//

#ifndef ASTEROIDS_MENU_H
#define ASTEROIDS_MENU_H

//#include "GameState.h"

class Menu {
private:
    sf::RenderWindow* window;
    //GameState nextState = Running;
public:

    void update();
    void draw();
    
    Menu(sf::RenderWindow* window);
    
    Menu();
};


#endif //ASTEROIDS_MENU_H

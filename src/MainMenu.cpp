// 
// Created by Adrian Valadkhani on 26.01.20.
//

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "MainMenu.h"
#include <iostream>

void MainMenu::update() {
}
sf::Vector2i Mouse_Click(){
    static bool pressed=false;
    sf::Vector2i position;
    while(true){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	    if(!pressed){
	        position = sf::Mouse::getPosition();
		pressed=true;
		break;
	    }
	} else {
	    pressed=false;
	}
    }
    return position;
}

bool MainMenu::display() {
    sf::Font font;
    float padding = 50;
    if(!font.loadFromFile("assets/arial.ttf")){return false;}
    sf::Text start;
    start.setString("START");
    start.setFont(font);
    start.setCharacterSize(100);
    start.setOutlineColor(sf::Color::White);
    start.setFillColor(sf::Color::White);
    float sWidth=start.getLocalBounds().width;
    float sHeight=start.getLocalBounds().height;
    float startx=window->getSize().x/2-sWidth/2;
    float starty=window->getSize().y/2-sHeight/2-padding;
    start.setPosition(startx,starty);
    window->draw(start);
    
    sf::Text exit;
    exit.setString("EXIT");
    exit.setFont(font);
    exit.setCharacterSize(100);
    exit.setOutlineColor(sf::Color::White);
    exit.setFillColor(sf::Color::White);
    float eWidth=exit.getLocalBounds().width;
    float eHeight=exit.getLocalBounds().height;
    float exitx=window->getSize().x/2-eWidth/2;
    float exity=window->getSize().y/2-eHeight/2+padding;
    exit.setPosition(exitx,exity);
    window->draw(exit);
    
    auto position = Mouse_Click();
    if (position.x>startx&&position.x<sWidth+startx&&position.y>starty+padding&&position.y<starty+sHeight+padding){
        std::cout << starty+padding+sHeight << " " << starty+padding << std::endl;
	return true;
    } else if (position.x>exitx&&position.x<eWidth+exitx&&position.y>exity+padding&&position.y<exity+eHeight+padding){
	window->close();
    }
    return false;
}


MainMenu::MainMenu(sf::RenderWindow* window) : window(window) {
}

MainMenu::MainMenu(){}


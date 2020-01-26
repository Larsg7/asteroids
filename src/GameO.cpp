// 
// Created by Adrian Valadkhani on 26.01.20.
//

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "GameO.h"
#include "Helper.h"

void GameO::update() {
}

bool GameO::display(int npoints) {
    sf::Font font;
    float padding = 50;
    if(!font.loadFromFile("assets/arial.ttf")){return false;}
    sf::Text start;
    start.setString("RESTART");
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

    sf::Text points;
    float padding2 = 10;
    points.setString(std::to_string(npoints));
    points.setPosition(padding2, window->getSize().y - padding2 - 110);

    points.setFont(font);
    points.setCharacterSize(100);

    points.setOutlineColor(sf::Color::Red);
    points.setFillColor(sf::Color::Red);

    window->draw(points);

    sf::Text GO ;
    GO.setString("GAMEOVER");
    GO.setFont(font);
    GO.setCharacterSize(100);
    GO.setOutlineColor(sf::Color::Red);
    GO.setFillColor(sf::Color::Red);
    float gWidth=GO.getLocalBounds().width;
    float gHeight=GO.getLocalBounds().height;
    float gox=window->getSize().x/2-gWidth/2;
    float goy=0;
    GO.setPosition(gox,goy);
    window->draw(GO);

    auto position = Helper::Mouse_Click();

    if (position.x>startx&&position.x<sWidth+startx&&position.y>starty+padding&&position.y<starty+sHeight+padding){
	return true;
    } else if (position.x>exitx&&position.x<eWidth+exitx&&position.y>exity+padding&&position.y<exity+eHeight+padding){
	window->close();
    }
    return false;
}


GameO::GameO(sf::RenderWindow* window) : window(window) {
}

GameO::GameO(){}


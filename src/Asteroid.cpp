// 
// Created by Adrian Valadkhani on 24.01.20.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Asteroid.h"
#include "Helper.h"

void Asteroid::setVel() {
   sf::Transform t;
   t.rotate(direction);
   velocity = t.transformPoint(sf::Vector2f(0,-1)) * speed;
}

void Asteroid::update() {
   setVel();
   updatePosition();
}

void Asteroid::draw(sf::RenderWindow *window) {
   sf::CircleShape circle(size);
   circle.setFillColor(sf::Color::Transparent);

   circle.setOutlineThickness(10.f);
   circle.setOutlineColor(sf::Color::White);
   circle.setOrigin(sf::Vector2f(80,80));
   circle.setPosition(position);
   window->draw(circle);
}

sf::Vector2f Asteroid::startPos(float xlen, float ylen){
   float xstart,ystart;
   startDir=rand()%5;
   switch(startDir){
       case 0:
           xstart=-size;
	   ystart=Helper::nextRandom(0,ylen);
	   break;
       case 1:
	   xstart=xlen+size;
	   ystart=Helper::nextRandom(0,ylen);
	   break;
       case 2:
           ystart=-size;
	   xstart=Helper::nextRandom(0,xlen);
	   break;
       case 3:
	   ystart=ylen+size;
	   xstart=Helper::nextRandom(0,xlen);
	   break;
       default:
           break;
   }
   return sf::Vector2f(xstart,ystart);
}

Asteroid::Asteroid(const sf::Vector2f &position, const sf::Vector2f &velocity) : MoveAble(position,velocity,0) {
    speed=Helper::nextRandom(minSpeed,maxSpeed);
    direction=Helper::nextRandom(0,360);
    size=Helper::nextRandom(minSize,maxSize);
}

Asteroid::Asteroid(){}


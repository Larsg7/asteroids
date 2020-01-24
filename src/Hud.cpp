//
// Created by Lars Groeber on 24.01.20.
//
#include <SFML/Graphics/Text.hpp>
#include "Hud.h"

void Hud::setLives(unsigned lives) {
    Hud::lives = lives;
}

void Hud::setPoints(unsigned points) {
    Hud::points = points;
}

void Hud::display() {
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        return;
    }
    sf::Text lives;
    sf::Text points;
    unsigned padding = 10;

    lives.setString(std::to_string(this->lives));
    points.setString(std::to_string(this->points));

    lives.setPosition(window->getSize().x - padding - 50, window->getSize().y - padding - 120);
    points.setPosition(padding, window->getSize().y - padding - 110);

    lives.setFont(font);
    points.setFont(font);
    lives.setCharacterSize(100);
    points.setCharacterSize(100);

    lives.setOutlineColor(sf::Color::White);
    lives.setFillColor(sf::Color::White);
    points.setOutlineColor(sf::Color::White);
    points.setFillColor(sf::Color::White);

    window->draw(lives);
    window->draw(points);
}

Hud::Hud(sf::RenderWindow *window) : window(window) {}

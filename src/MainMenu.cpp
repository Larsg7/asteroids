// 
// Created by Adrian Valadkhani on 26.01.20.
//

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "MainMenu.h"
#include "Asteroids.h"
#include "Helper.h"

void MainMenu::update() {
}

// Display the main menu
void MainMenu::display() {
    sf::Font font;
    padding = 50;
    if (!font.loadFromFile("assets/arial.ttf")) { return; }

    // --- Button: Start ---
    sf::Text start;
    start.setString("START");
    start.setFont(font);
    start.setCharacterSize(100);
    start.setOutlineColor(sf::Color::White);
    start.setFillColor(sf::Color::White);
    sWidth = start.getLocalBounds().width;
    sHeight = start.getLocalBounds().height;
    startx = window->getSize().x / 2 - sWidth / 2;
    starty = window->getSize().y / 2 - sHeight / 2 - padding;
    start.setPosition(startx, starty);
    window->draw(start);
    // --- ------------- ---

    // --- Button: Exit ---
    sf::Text exit;
    exit.setString("EXIT");
    exit.setFont(font);
    exit.setCharacterSize(100);
    exit.setOutlineColor(sf::Color::White);
    exit.setFillColor(sf::Color::White);
    eWidth = exit.getLocalBounds().width;
    eHeight = exit.getLocalBounds().height;
    exitx = window->getSize().x / 2 - eWidth / 2;
    exity = window->getSize().y / 2 - eHeight / 2 + padding;
    exit.setPosition(exitx, exity);
    window->draw(exit);
    // --- ------------ ---
}



MainMenu::MainMenu() {}

// add the functionality of a button
void MainMenu::acceptInput(sf::Event &event) {
    if (event.type != sf::Event::MouseButtonPressed) {
        return;
    }
    auto position = sf::Mouse::getPosition(*window);
    if (position.x > startx && position.x < sWidth + startx && position.y > starty + padding &&
        position.y < starty + sHeight + padding) { // click text START to start
        asteroids->gameState = Starting;
    } else if (position.x > exitx && position.x < eWidth + exitx && position.y > exity + padding &&
               position.y < exity + eHeight + padding) { // click EXIT to exit
        asteroids->gameState = Quitting;
    }
}

MainMenu::MainMenu(sf::RenderWindow *window, Asteroids *asteroids) : window(window), asteroids(asteroids) {}



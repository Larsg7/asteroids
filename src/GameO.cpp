// 
// Created by Adrian Valadkhani on 26.01.20.
//

#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "GameO.h"
#include "Helper.h"
#include "GameState.h"
#include "Asteroids.h"

void GameO::update() {
}

// dipaly the gameover screen
void GameO::display(int npoints) {
    sf::Font font;
    padding = 50;
    if (!font.loadFromFile("assets/arial.ttf")) { return; }
    // --- Button: Restart ---
    sf::Text start;
    start.setString("RESTART");
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
    // --- --------------- ---

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

    // --- Display: Score ---
    sf::Text points;
    padding2 = 10;
    points.setString(std::to_string(npoints));
    points.setPosition(padding2, window->getSize().y - padding2 - 110);
    points.setFont(font);
    points.setCharacterSize(100);
    points.setOutlineColor(sf::Color::Red);
    points.setFillColor(sf::Color::Red);
    window->draw(points);
    // --- -------------- ---

    // --- Display: Gameover ---
    sf::Text GO;
    GO.setString("GAMEOVER");
    GO.setFont(font);
    GO.setCharacterSize(100);
    GO.setOutlineColor(sf::Color::Red);
    GO.setFillColor(sf::Color::Red);
    gWidth = GO.getLocalBounds().width;
    gHeight = GO.getLocalBounds().height;
    gox = window->getSize().x / 2 - gWidth / 2;
    goy = 0;
    GO.setPosition(gox, goy);
    window->draw(GO);
    // --- ----------------- ---
}


GameO::GameO() {}

// similar to the main menu check where mouse did click
void GameO::acceptInput(sf::Event &event) {
    if (event.type != sf::Event::MouseButtonPressed) {
        return;
    }
    auto position = sf::Mouse::getPosition(*window);
    if (position.x > startx && position.x < sWidth + startx && position.y > starty + padding &&
        position.y < starty + sHeight + padding) {
        asteroids->gameState = Menu; // if restart then go to main menu
    } else if (position.x > exitx && position.x < eWidth + exitx && position.y > exity + padding &&
               position.y < exity + eHeight + padding) {
        asteroids->gameState = Quitting; // if exit the exit the game
    }
}

GameO::GameO(sf::RenderWindow *window, Asteroids *asteroids) : window(window), asteroids(asteroids) {}


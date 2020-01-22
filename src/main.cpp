#include <iostream>
#include <SFML/Graphics.hpp>
#include "Asteroids.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");

    Asteroids asteroids(&window);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        asteroids.run();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            asteroids.acceptInput(event);
        }
        window.display();
    }
    return 0;
}
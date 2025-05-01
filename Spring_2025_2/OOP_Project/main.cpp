#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "map.h"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tower Game");
    window.setFramerateLimit(60);

    sf::Texture grassTexture;
    sf::Texture towerTexture;
    sf::Texture pathTexture;

    if (!grassTexture.loadFromFile("images/grass.jpeg") ||
        !towerTexture.loadFromFile("images/tower.png") ||
        !pathTexture.loadFromFile("images/path.jpg")) {
        throw std::runtime_error("Failed to load textures");
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        Map::drawMap(window, grassTexture, towerTexture, pathTexture);
        window.display();
    }
    return 0;
}
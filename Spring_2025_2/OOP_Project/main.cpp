#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "map.h"
#include "zombie.h"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Tower Game");
    window.setFramerateLimit(60);

    sf::Texture grassTexture;
    sf::Texture towerTexture;
    sf::Texture pathTexture;
    sf::Texture chestTexture;
    sf::Texture zombieTexture;

    const int tileSize = Map::tileSize;
    std::vector<sf::Vector2f> path = {
        {3 * tileSize, 0 * tileSize},
        {3 * tileSize, 1 * tileSize},
        {3 * tileSize, 2 * tileSize},
        {3 * tileSize, 3 * tileSize},
        {4 * tileSize, 4 * tileSize},
        {5 * tileSize, 5 * tileSize},
        {5 * tileSize, 6 * tileSize},
        {5 * tileSize, 7 * tileSize},
        {5 * tileSize, 8 * tileSize},
    };
    if (!grassTexture.loadFromFile("images/grass.jpeg") ||
        !towerTexture.loadFromFile("images/tower.png") ||
        !pathTexture.loadFromFile("images/path.jpg") || 
        !chestTexture.loadFromFile("images/chest.jpg") ||
        !zombieTexture.loadFromFile("images/zombie.png")) {
        throw std::runtime_error("failed to load textures");
    }

    Zombie zombie(zombieTexture, path);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        Map::drawMap(window, grassTexture, towerTexture, pathTexture, chestTexture);
        float deltaTime = clock.restart().asSeconds();
        zombie.update(deltaTime);
        zombie.draw(window);
        window.display();
    }
    return 0;
}
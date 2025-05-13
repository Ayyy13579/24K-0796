#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "map.h"
#include "zombie.h"
#include "wave.h"
#include <iostream>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Tower Game");
    window.setFramerateLimit(60);

    sf::Texture grassTexture;
    sf::Texture towerTexture;
    sf::Texture pathTexture;
    sf::Texture chestTexture;
    sf::Texture regzombieTexture;
    sf::Texture fastzombieTexture;
    sf::Texture strzombieTexture;

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
        !regzombieTexture.loadFromFile("images/zombie.png") ||
        !fastzombieTexture.loadFromFile("images/fastzombie.png") ||
        !strzombieTexture.loadFromFile("images/strongzombie.png")) {
        std::cerr << "Error loading textures" << std::endl;
    }

    Waves waves(regzombieTexture, fastzombieTexture, strzombieTexture, path);
    sf::Clock clock;
    float spawnTimer = 0.0f;
    int zombiesSpawned = 0;
    const int maxZombies = 5;
    bool damage = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::E) {
                    damage = true;
                }
            }
        }
        window.clear();
        Map::drawMap(window, grassTexture, towerTexture, pathTexture, chestTexture);
        float deltaTime = clock.restart().asSeconds();
        waves.update(deltaTime);
        waves.drawZombies(window);
        if (damage) {
            for (Zombie* z : waves.getZombies()) {
                z->takeDamage(1);
            }
            damage = false;
        }
        window.display();
    }
}
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "map.h"
#include "zombie.h"
#include "wave.h"
#include "tower.h"
#include "bullet.h"
#include <iostream>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Tower Defense");
    window.setFramerateLimit(60);

    // Load textures
    sf::Texture grassTexture, towerTexture, pathTexture, chestTexture;
    sf::Texture regZombieTexture, fastZombieTexture, strongZombieTexture;

    if (!grassTexture.loadFromFile("resources/grass.jpeg") ||
        !towerTexture.loadFromFile("resources/tower.png") ||
        !pathTexture.loadFromFile("resources/path.jpg") ||
        !chestTexture.loadFromFile("resources/chest.jpg") ||
        !regZombieTexture.loadFromFile("resources/zombie.png") ||
        !fastZombieTexture.loadFromFile("resources/fastzombie.png") ||
        !strongZombieTexture.loadFromFile("resources/strongzombie.png")) {
        std::cerr << "Failed to load textures!" << std::endl;
        return 1;
    }

    // Initialize game components
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
        {5 * tileSize, 8 * tileSize}
    };

    Waves waves(regZombieTexture, fastZombieTexture, strongZombieTexture, path);
    std::vector<Tower> towers;

    // Add custom towers
    const sf::Vector2f tower1Pos(1 * tileSize + tileSize/2, 3 * tileSize + tileSize/2);
    const sf::Vector2f tower2Pos(7 * tileSize + tileSize/2, 7 * tileSize + tileSize/2);

    // Create towers with parameters (position, range, attacks-per-second)
    towers.emplace_back(tower1Pos, towerTexture, 300.0f, 1.5f);
    towers.emplace_back(tower2Pos, towerTexture, 300.0f, 1.5f);

    sf::Clock clock;
    bool damage = false;

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        // Update game state
        waves.update(deltaTime);
        auto zombies = waves.getZombies();

        // Update towers
        for (auto& tower : towers) {
            tower.update(deltaTime, zombies);
        }

        // Handle manual damage input
        if (damage) {
            for (Zombie* z : zombies) {
                z->takeDamage(1);
            }
            damage = false;
        }

        // Render
        window.clear();
        
        // Draw game world
        Map::drawMap(window, grassTexture, towerTexture, pathTexture, chestTexture);
        waves.drawZombies(window);

        // Draw tower projectiles
        for (auto& tower : towers) {
            tower.draw(window);
        }

        window.display();
    }

    return 0;
}

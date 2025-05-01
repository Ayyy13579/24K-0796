#include <SFML/Graphics.hpp>
#include "map.h"


void Map::drawMap(sf::RenderWindow& window, sf::Texture& grassTexture, sf::Texture& towerTexture, sf::Texture& pathTexture) {

    grassTexture.setSmooth(true);
    towerTexture.setSmooth(true);
    pathTexture.setSmooth(true);
    int map[width][height] = {
        {0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
        {0, 0, 3, 0, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 2, 0, 0, 0},
        {0, 0, 0, 0, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 2, 2, 2, 0, 0, 0, 0},
        {0, 0, 2, 2, 2, 0, 0, 3, 0, 0},
        {0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sf::Sprite sprite;
            switch (map[i][j]) {
                case 0:
                    sprite.setTexture(grassTexture);
                    break;
                case 2:
                    sprite.setTexture(pathTexture);
                    break;
                case 3:
                    sprite.setTexture(towerTexture);
                    float scaleX = static_cast<float>(100) / towerTexture.getSize().x;
                    float scaleY = static_cast<float>(100) / towerTexture.getSize().y;
                    sprite.setScale(scaleX, scaleY);
                    break;
            }
            sprite.setPosition(j * tileSize, i * tileSize);
            window.draw(sprite);
        }
    }
}
#include <SFML/Graphics.hpp>

class Map {
    public:
    static const int width = 10;
    static const int height = 10;
    static const int tileSize = 100;

    static void drawMap(sf::RenderWindow& window, sf::Texture& grassTexture, sf::Texture& towerTexture, sf::Texture& pathTexture);
};
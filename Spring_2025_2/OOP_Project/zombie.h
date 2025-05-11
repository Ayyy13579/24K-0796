#include <SFML/Graphics.hpp>
#include <vector>

class Zombie {
    private:
    sf::Sprite sprite;
    std::vector<sf::Vector2f> path;
    float speed;
    int health;
    int currentTargetIndex;

    public:
    Zombie(sf::Texture& texture, const std::vector<sf::Vector2f>& path);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void takeDamage(int damage);
    bool isDead() const { return health <= 0; } 
    bool reachedEnd() const;
};
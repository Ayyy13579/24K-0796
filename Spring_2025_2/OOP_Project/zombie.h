#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Zombie {
    protected:
    sf::Sprite sprite;
    std::vector<sf::Vector2f> path;
    float speed;
    int health;
    int currentTargetIndex;

    public:
    Zombie(sf::Texture& texture, const std::vector<sf::Vector2f>& path);
    sf::Vector2f getPosition() const { return sprite.getPosition(); }
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void takeDamage(int damage);
    bool isDead() const { return health <= 0; } 
    bool reachedEnd() const;
};

class FastZombie : public Zombie {
    public:
    FastZombie(sf::Texture& texture, const std::vector<sf::Vector2f>& path);
};

class StrongZombie : public Zombie {
    public:
    StrongZombie(sf::Texture& texture, const std::vector<sf::Vector2f>& path);
};

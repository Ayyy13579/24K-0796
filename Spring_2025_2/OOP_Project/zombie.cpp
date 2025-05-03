#include <SFML/Graphics.hpp>
#include "zombie.h"
#include <cmath>

Zombie::Zombie(sf::Texture& texture, const std::vector<sf::Vector2f>& path, float speed, int health)
    : path(path), speed(speed), health(health), currentTargetIndex(0) {
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition(path[0]);
}

void Zombie::takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            health = 0;
        }
}

bool Zombie::reachedEnd() const {
    return currentTargetIndex >= path.size();
}

void Zombie::update(float deltaTime) {
    if (isDead() || reachedEnd()) {
        return;
    }
    sf::Vector2f position = sprite.getPosition();
    sf::Vector2f target = path[currentTargetIndex];
    sf::Vector2f direction = target - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance != 0) {
        direction /= distance;
    }
    sprite.move(direction * speed * deltaTime);
    if (distance < speed * deltaTime) {
        currentTargetIndex++;
        if (currentTargetIndex < path.size()) {
            sprite.setPosition(path[currentTargetIndex]);
        }
    }
}

void Zombie::draw(sf::RenderWindow& window) {
    if (!isDead()) {
        window.draw(sprite);
    }
}
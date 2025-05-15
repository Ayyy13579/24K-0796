#pragma once
#include <SFML/Graphics.hpp>
#include "zombie.h"
#include <cmath>

class Bullet {
private:
    sf::CircleShape shape;
    Zombie* target;
    float speed;
    int damage;
    bool active;
    static constexpr float HIT_RANGE = 10.0f;

public:
    Bullet(sf::Vector2f startPosition, Zombie* target, float speed = 500.0f, int damage = 1)
        : target(target), speed(speed), damage(damage), active(true) {
        shape.setRadius(5);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(startPosition);
    }

     void update(float deltaTime) {
        if (!active || !target || target->isDead()) return;

        sf::Vector2f direction = target->getPosition() - shape.getPosition();
        float distance = std::hypot(direction.x, direction.y);
        
        if (distance > HIT_RANGE) {
            direction /= distance;
            shape.move(direction * speed * deltaTime);
        } else {
            target->takeDamage(damage);
            active = false;
        }
    }

    void draw(sf::RenderWindow& window) const {
        if (active) window.draw(shape);
    }

    bool isActive() const { return active; }
};
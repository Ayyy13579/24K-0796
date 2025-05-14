#pragma once
#include <vector>
#include "bullet.h"
#include "zombie.h"
#include <math.h>

class Tower {
private:
    sf::Vector2f position;
    float cooldown;
    float range;
    std::vector<Bullet> bullets;
    float attackSpeed;
    static constexpr float FIRE_RATE = 1.0f;
    sf::Sprite sprite;


public:
    Tower(sf::Vector2f pos, const sf::Texture& texture, float range = 300.0f, float attackSpeed = 1.5f)
    : position(pos), range(range), attackSpeed(attackSpeed), cooldown(0.0f) {
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
    sprite.setPosition(position);
    float scaleX = Map::tileSize / static_cast<float>(texture.getSize().x);
    float scaleY = Map::tileSize / static_cast<float>(texture.getSize().y);
    float uniformScale = std::min(scaleX, scaleY);
    sprite.setScale(uniformScale*1.2, uniformScale*1.2);
 // Optional: Scale it to fit your tile size
    }


        void update(float deltaTime, std::vector<Zombie*>& zombies) {
        cooldown -= deltaTime;
        
        // Find closest alive zombie within range
        Zombie* nearest = nullptr;
        float minDistance = std::numeric_limits<float>::max();
        
        for (auto zombie : zombies) {
            if (zombie->isDead()) continue;
            
            float dx = position.x - zombie->getPosition().x;
            float dy = position.y - zombie->getPosition().y;
            float distance = std::hypot(dx, dy);
            
            if (distance < range && distance < minDistance) {
                minDistance = distance;
                nearest = zombie;
            }
        }

        // Shoot at target
        if (nearest && cooldown <= 0) {
            bullets.emplace_back(position, nearest);
            cooldown = 1.0f / attackSpeed;
        }

        // Update bullets
        for (auto& bullet : bullets) {
            bullet.update(deltaTime);
        }

        // Remove inactive bullets
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(),
                [](const Bullet& b) { return !b.isActive(); }),
            bullets.end());
    }


    void draw(sf::RenderWindow& window) const {
    window.draw(sprite);
    for (const auto& bullet : bullets) {
        bullet.draw(window);
        }
    }

};
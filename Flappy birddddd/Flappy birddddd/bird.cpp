#include "Bird.h"

Bird::Bird(const std::string& texturePath) : velocityY(0) {
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load bird texture");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setPosition(100, 300);
}

void Bird::update(float deltaTime) {
    velocityY += gravity * deltaTime;
    sprite.move(0, velocityY * deltaTime);
    if (sprite.getPosition().y > 550) {
        sprite.setPosition(sprite.getPosition().x, 550);
        velocityY = 0;
    }
}

void Bird::jump() {
    velocityY = jumpSpeed;
}

sf::Sprite& Bird::getSprite() {
    return sprite;
}

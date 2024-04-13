#pragma once
#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird(const std::string& texturePath);
    void update(float deltaTime);
    void jump();
    sf::Sprite& getSprite();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float velocityY;
    static constexpr float gravity = 1000.0f;
    static constexpr float jumpSpeed = -350.0f;
};

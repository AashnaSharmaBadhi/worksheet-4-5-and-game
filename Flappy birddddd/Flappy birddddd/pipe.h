#pragma once
#include <SFML/Graphics.hpp>

class Pipe {
public:
    Pipe(const sf::Vector2f& position, const sf::Vector2f& size);
    void update(float deltaTime);
    sf::RectangleShape& getShape();

private:
    sf::RectangleShape shape;
    static constexpr float speed = -200.0f;
};

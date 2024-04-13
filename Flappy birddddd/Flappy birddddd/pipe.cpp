#include "Pipe.h"

Pipe::Pipe(const sf::Vector2f& position, const sf::Vector2f& size) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Green);
}

void Pipe::update(float deltaTime) {
    shape.move(speed * deltaTime, 0);
    if (shape.getPosition().x + shape.getSize().x < 0) {
        shape.setPosition(800, shape.getPosition().y);
    }
}

sf::RectangleShape& Pipe::getShape() {
    return shape;
}


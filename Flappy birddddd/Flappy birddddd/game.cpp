#include "Game.h"
#include<iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Flappy Bird"), bird("bird.png"), isRunning(true) {
    initPipes();
}

void Game::run() {
    while (window.isOpen() && isRunning) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            bird.jump();
    }
}

void Game::update() {
    float deltaTime = clock.restart().asSeconds();
    bird.update(deltaTime);
    for (auto& pipe : pipes)
        pipe.update(deltaTime);
    checkCollisions();
}

void Game::render() {
    window.clear(sf::Color::Cyan); // Clear with sky blue color
    for (auto& pipe : pipes)
        window.draw(pipe.getShape());
    window.draw(bird.getSprite());
    window.display();
}

void Game::checkCollisions() {
    for (auto& pipe : pipes) {
        if (pipe.getShape().getGlobalBounds().intersects(bird.getSprite().getGlobalBounds())) {
            std::cout << "Collision Detected!" << std::endl;
            isRunning = false;
            break;
        }
    }
}

void Game::initPipes() {
    // Initialize pipes at different positions
    pipes.emplace_back(sf::Vector2f(600, 0), sf::Vector2f(100, 250)); // Top pipe
    pipes.emplace_back(sf::Vector2f(600, 350), sf::Vector2f(100, 250)); // Bottom pipe
}

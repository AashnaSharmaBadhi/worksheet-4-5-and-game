#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    Bird bird;
    std::vector<Pipe> pipes;
    sf::Clock clock;
    bool isRunning;

    void processEvents();
    void update();
    void render();
    void checkCollisions();
    void initPipes();
};

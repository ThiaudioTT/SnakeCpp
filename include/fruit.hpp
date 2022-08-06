#pragma once

#include <SFML/Graphics.hpp>
#include "./snake.hpp"
#include <cstdlib>
#include <time.h>

class Fruit {
private:
    sf::RectangleShape fruitBody;
    sf::Vector2f fruitPosition;

public:
    Fruit(sf::Color c);

    // Generate or destroy current fruit.
    void generate();
    sf::Vector2f position() {return fruitPosition;}
    void draw(sf::RenderWindow &window);


    /**
     * @brief Function that checks collision with the fruit and the snake
     * Generates a new function and destroy the last whe the collision is done. 
     * 
     * @param snake 
     */
    void isEaten(Snake &snake);
};

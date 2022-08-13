#pragma once

#include <SFML/Graphics.hpp>
#include "./snake.hpp"
#include <cstdlib>
#include <time.h>


/**
 * @brief class for represent The fruits 
 * 
 */
class Fruit {
private:
    sf::RectangleShape fruitBody;
    sf::Vector2f fruitPosition;

public:
    Fruit(sf::Color c);

    /**
     * @brief generate/update the current fruit in the map
     * Use sf::sleep and std::srand for seed and random numbers.
     * 
     */
    void generate();

    /**
     * @return sf::Vector2f 
     */
    sf::Vector2f position() {return fruitPosition;}

    /**
     * @brief Draw the fruit in the current window
     * 
     * @param window 
     */
    void draw(sf::RenderWindow &window);


    /**
     * @brief Function that checks collision with the fruit and the snake
     * Generates a new function and destroy the last whe the collision is done. 
     * 
     * It use fruit::generate()
     * @param snake 
     * @return boolean value
     */
    bool isEaten(Snake &snake);
};

#pragma once

#include <SFML/Graphics.hpp>
#include <deque>

constexpr int pixel = 12; // this will be the pixel of our snake

// global var to define the max speed, to be used in the program
constexpr int maxSpeed = 12;

/**
 * @brief struct speed to Snake use.
 * 
 */
struct Speed {
    int x = 12;
    int y = 12;
};

/**
 * @brief Class to represent the snake.
 * Use struct speed and probably others...?
 * 
 */
class Snake {
private:
    std::deque<sf::RectangleShape> snakeBody;
    std::deque<sf::Vector2f> snakePosition;

    Speed speed;

    int _direction = 3;
public:

    Snake();

    /**
     * @brief Draw the snake in the current window
     * 
     * @param window 
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief update snake coordinates (move the snake in a direction).
     * The direction is clock based.
     * It use struct speed
     * 
     * @param direction [0,3]
     */
    void move(int d);

    /**
     * @brief Grow the snake using std::deque
     * 
     */
    void grow();

    /**
     * @brief update direction.
     * Clock based. 0 - 1
     * 
     * @param integer 0 - 3 
     */
    void direction(int d);

    /**
     * @return int direction
     */
    int direction(){return _direction;};

    /**
     * @brief return the position of the head
     * 
     * @return sf::Vector2f head
     */
    sf::Vector2f getHeadP(){return snakePosition[0];};

    /**
     * @brief Get the Node object
     * 
     * @param n 
     * @return sf::Vector2f part of snakeBody
     */
    sf::Vector2f getNode(int n);


    /**
     * @brief Function to check collision
     * 
     * @return integer 0 if ok, integer -1 if is colliding.
     */
    int checkCollision();
};

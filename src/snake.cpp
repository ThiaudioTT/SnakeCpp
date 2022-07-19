#include <snake.hpp>

snake::snake(sf::Vector2f head, sf::Vector2f tail)
{
    snakeBody.push_back(head);
    snakeBody.push_back(tail);

    
    snakePosition.push_back(head);
    snakePosition.push_back(tail);
}
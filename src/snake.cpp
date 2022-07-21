#include "../include/snake.hpp"
using namespace sf;

snake::snake()
{
    // 1 pixel is 1 
    snakePosition = {Vector2f(400, 300), Vector2f(400 + pixel, 300), Vector2f(400 + 2 * pixel, 300)}; //coordinates, center. Attention to window width, clean code after
    // snakePosition.push_back(Vector2f(400, 300));
}
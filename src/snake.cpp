#include "../include/snake.hpp"
#include <iostream>
using namespace sf;

Snake::Snake()
{
    snakeBody = {RectangleShape(Vector2f(12,12))};
    snakePosition = {Vector2f(400, 300)}; 
}

/*
Draw the snake in the giving window
*/
void Snake::draw(RenderWindow &window)
{
    for(int i = 0; i < snakeBody.size(); i++)
    {
        snakeBody[i].setPosition(snakePosition[i]);
        window.draw(snakeBody[i]);
    }

}

/*
Update snake coordinates
*/
void Snake::move(int d)
{

    // TODO, COLISION
    // maybe if altering directions to 1 and -1, 2 and -2 shall solve
    //if(direction == d) // obs (this is ugly break code)
      //  return; // do nothing!

    switch(d)
    {
        case 0: // up
            speed.x = 0;
            speed.y = -maxSpeed;
            break;
        case 1:
            speed.x = maxSpeed;
            speed.y = 0;
            break;
        case 2:
            speed.x = 0;
            speed.y = maxSpeed;
           break;
        case 3:
            speed.x = -maxSpeed;
            speed.y = 0;
            break; 
        
        default:
            std::cerr << "SNAKE MOVE EXPECTED";
            throw Snake{};
            break;
    }

    const int newHeadx = snakePosition[0].x + speed.x;    
    const int newHeady = snakePosition[0].y + speed.y;

    snakePosition.push_front(sf::Vector2f(newHeadx, newHeady));
    snakePosition.pop_back();
}

void Snake::grow()
{
    snakePosition.push_back(snakePosition[snakePosition.size() - 1]);
    snakeBody.push_back(RectangleShape(Vector2f(12,12)));
}
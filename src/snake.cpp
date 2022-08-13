#include "../include/snake.hpp"
#include <iostream>
using namespace sf;

Snake::Snake()
{
    snakeBody = {RectangleShape(Vector2f(12,12))};
    snakeBody[0].setFillColor(sf::Color::Yellow);
    snakePosition = {Vector2f(396, 300)}; // they need to be multiples of 12
}

void Snake::draw(RenderWindow &window)
{
    for(int i = 0; i < snakeBody.size(); i++)
    {
        snakeBody[i].setPosition(snakePosition[i]);
        window.draw(snakeBody[i]);
    }

}

void Snake::move(int d)
{
    // snake::direction will deal with internal movement
    switch(d)
    {
        // I want to move to...:
        case 0: // up
            speed.x = 0;
            speed.y = -maxSpeed;
            break;
        case 1: // right (clockwork system)
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

    const sf::Vector2f newHead(snakePosition[0].x + speed.x, 
                            snakePosition[0].y + speed.y);

    snakePosition.push_front(newHead);
    snakePosition.pop_back();
}

void Snake::grow()
{
    snakePosition.push_back(snakePosition[snakePosition.size() - 1]);
    snakeBody.push_back(RectangleShape(Vector2f(12,12)));
}


void Snake::direction(int d)
{

    // TODO there are better forms to do this.
    if(_direction == 0 && d == 2)
        return;
    if(_direction == 1 && d == 3)
        return;
    if(_direction == 2 && d == 0)
        return;
    if(_direction == 3 && d == 1)
        return;
    
    _direction = d;
}

sf::Vector2f Snake::getNode(int n)
{
    if(n > snakePosition.size())
    {
        std::cerr << "OUT OF BOUNDS ARRAY, SNAKE::GETNODE EXPECTED";
        throw int{};
    }

    return snakePosition[n];
};

int Snake::checkCollision()
{
    for(int i = 1; i < snakePosition.size(); i++)
    {
        if(snakePosition[0].x == snakePosition[i].x && snakePosition[0].y == snakePosition[i].y)
        {
            // TODO: probably there's a bug here.
            std::cout << "SNAKE COLLISION DETECTED" << std::endl;
            std::cout << "Current head position: X: " << snakePosition[0].x << " Y: " << snakePosition[0].y << "\n"
                        << "Node: " << i << ", X: " << snakePosition[i].x << " Y: " << snakePosition[i].y << "\n"; 
            return -1;
        }
    }

    return 0;
}

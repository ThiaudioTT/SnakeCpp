#include <SFML/Graphics.hpp>
#include <deque>
// #include "../include/board.hpp"

constexpr int pixel = 12; // this will be the pixel of our snake

constexpr int maxSpeed = 12;
struct Speed {
    int x = 12;
    int y = 12;
};

// invariant: A snake is a snake, yaay
class Snake {
private:
    std::deque<sf::RectangleShape> snakeBody;
    std::deque<sf::Vector2f> snakePosition;

    Speed speed;

public:
    int direction = 0; // head direction TODO PRIVATE MEMBER

    Snake();
    void draw(sf::RenderWindow &window);
    void move(int d);
    void grow();
};
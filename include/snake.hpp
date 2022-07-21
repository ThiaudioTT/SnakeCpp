#include <SFML/Graphics.hpp>
#include <deque>

constexpr int pixel = 12; // this will be the pixel of our snake


class snake {
private:
    std::deque<sf::RectangleShape> snakeBody;
    std::deque<sf::Vector2f> snakePosition;

public:

    snake();
    void move();
    void grow();
};
#include <SFML/Graphics.hpp>
#include <deque>

class snake {
private:
    std::deque<sf::Vector2f> snakeBody;
    std::deque<sf::RectangleShape> snakePosition;

public:
    snake(sf::Vector2f head, sf::Vector2f tail);
    void move();
    void grow();
};
#include <SFML/Graphics.hpp>
#include <deque>

constexpr int pixel = 12; // this will be the pixel of our snake

constexpr int maxSpeed = 2;
struct Speed {
    int x = 2;
    int y = 2;
};

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
#include <SFML/Graphics.hpp>
#include <deque>

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

    int _direction = 3;
public:

    Snake();
    void draw(sf::RenderWindow &window);
    void move(int d);
    void grow();

    // Change and return direction
    void direction(int d);
    int direction(){return _direction;};

    // positions functions
    sf::Vector2f getHeadP(){return snakePosition[0];};
    sf::Vector2f getNode(int n);

    int checkCollision();

};

#include "../include/fruit.hpp"
#include <iostream> // debug
using namespace sf;

Fruit::Fruit(sf::Color c)
{
    fruitBody = RectangleShape(Vector2f(12, 12));
    fruitBody.setFillColor(c);

    sf::sleep(sf::seconds(1)); // we need to wait and generate because of srand();
    generate(); 
}

void Fruit::generate()
{
    std::srand(std::time(nullptr) * 1000);

    // here we need to generate multiples of 12.
    // TODO, AVOID MAGIC CONSTANTS!
    constexpr int maxX = 49; // 600 (windowWidth) / 12 (pixel) = 50, 50 - 1 = 49
    constexpr int maxY = 32; // 396 / 12 = 33, 33 - 1 = 32
    sf::Vector2f random = Vector2f(((rand() % maxX) * 12), (rand() % maxY) * 12); // simple math here, I will explain later
    std::cout << "X: " << random.x << " Y: " << random.y << std::endl;

    fruitPosition = random;
    fruitBody.setPosition(fruitPosition);
}

void Fruit::draw(RenderWindow &window)
{
    window.draw(fruitBody);
}

bool Fruit::isEaten(Snake &snake)
{
    if (fruitPosition.x == snake.getHeadP().x && fruitPosition.y == snake.getHeadP().y)
    {
        generate(); // generate new fruit
        snake.grow(); // refactor: think about if snake should grow here
        return true;
    }
    return false;
}

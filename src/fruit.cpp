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
    std::srand(std::time(0));

    // here we need to generate multiples of 12.
    // TODO, AVOID MAGIC CONSTANTS!
    sf::Vector2f random = Vector2f(((rand() % 49) * 12), (rand() % 33) * 12); // simple math here, I will explain later
    std::cout << "X: " << random.x << " Y: " << random.y << std::endl;
    fruitPosition = random;
    fruitBody.setPosition(fruitPosition);
}

void Fruit::draw(RenderWindow &window)
{
    window.draw(fruitBody);
}

void Fruit::isEaten(Snake &snake)
{
    if (fruitPosition.x == snake.getHeadP().x && fruitPosition.y == snake.getHeadP().y)
    {
        generate(); // generate new fruit
        snake.grow();
    }
}

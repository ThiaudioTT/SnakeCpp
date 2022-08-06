#include "../include/fruit.hpp"
#include <iostream> // debug
using namespace sf;

Fruit::Fruit(sf::Color c)
{
    fruitBody = RectangleShape(Vector2f(12,12));
    fruitBody.setFillColor(c);
}

void Fruit::generate()
{
    std::srand(std::time(0));

    // here we need to generate multiples of 12.
    sf::Vector2f random =  Vector2f( ( (rand() % 67) * 12 ), (rand() %  50) * 12); // simple math here, I will explain later
    std::cout << "X: " << random.x << " Y: " << random.y << std::endl;
    fruitPosition = random;
    fruitBody.setPosition(fruitPosition);
}


void Fruit::draw(RenderWindow &window)
{
    window.draw(fruitBody);
}
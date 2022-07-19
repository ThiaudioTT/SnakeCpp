#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream> // for debug

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

// main will deal with the loop
int main()
{
   sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake"); //, sf::Style::Titlebar); // fixed size
   window.setFramerateLimit(60);

    std::deque<sf::RectangleShape> snakeBody = {
        sf::RectangleShape(sf::Vector2f(12,12)), // head
        sf::RectangleShape(sf::Vector2f(12,12)) // tail
        };

   while (window.isOpen())
   {
      // Render
      window.clear(sf::Color::Black);

      snakeBody[0].setPosition(sf::Vector2f(400, 300));
      snakeBody[1].setPosition(sf::Vector2f(400 + 12, 300));
      for(int i = 0; i < snakeBody.size(); i++)
        window.draw(snakeBody[i]);
      window.display();
   }
}

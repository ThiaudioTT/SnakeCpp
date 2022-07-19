#include <SFML/Graphics.hpp>

#include <iostream> // for debug

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

// main will deal with the loop
int main()
{
   sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake"); //, sf::Style::Titlebar); // fixed size
   window.setFramerateLimit(60);

   // snake body
   sf::RectangleShape snake;
   snake.setSize(sf::Vector2f(12, 12));

   // position
   sf::Vector2f snakePosition(windowWidth / 2, windowHeight / 2);
   snake.setPosition(snakePosition); // set the snake position to center

   // default velocity snake
   const int maxVelocity = 2;

   float xVelocity = -maxVelocity;
   float yVelocity = 0;

   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event)) // deal with event keyboards and close window
      {
         if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
         {
            window.close();
            return 0;
         }
         else if (sf::Event::KeyPressed) // others keyboards
         {
            switch (event.key.code)
            {
            case sf::Keyboard::W: // up
               std::cout << "W PRESSED" << std::endl;
               xVelocity = 0;
               yVelocity = -maxVelocity;
               break;

            case sf::Keyboard::A: // left
               std::cout << "A PRESSED" << std::endl;
               xVelocity = -maxVelocity;
               yVelocity = 0;
               break;

            case sf::Keyboard::S:
               std::cout << "S PRESSED" << std::endl;
               xVelocity = 0;
               yVelocity = maxVelocity;
               break;

            case sf::Keyboard::D:
               std::cout << "D PRESSED" << std::endl;
               xVelocity = maxVelocity;
               yVelocity = 0;
               break;
               
            default:
               break;
            }
         }
      }

      // default movement of the snake
      snakePosition.x += xVelocity;
      snakePosition.y += yVelocity;

      snake.setPosition(40,2);

      // Render
      window.clear(sf::Color::Black);
      window.draw(snake);
      window.display();
   }
}

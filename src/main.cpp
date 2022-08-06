#include <SFML/Graphics.hpp>
#include "../include/snake.hpp"
#include "../include/fruit.hpp"
#include <iostream> // for debug

constexpr int windowWidth = 600;
constexpr int windowHeight = 396; // 400, but 396 is multiple of 12 (pixel)

int main()
{
   sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake", sf::Style::Titlebar);
   window.setFramerateLimit(30);
   window.setKeyRepeatEnabled(false);

   Snake snake;

   // DEFINING FRUITS
   Fruit apple(sf::Color::Red);
   apple.generate();

   Fruit grape(sf::Color::Magenta);
   grape.generate();

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
         else if (event.type == sf::Event::KeyPressed) // others keys
         {
            switch (event.key.code)
            {
            case sf::Keyboard::W: // up
               std::cout << "W PRESSED" << std::endl;
               snake.direction(0);
               break;

            case sf::Keyboard::D:
               std::cout << "D PRESSED" << std::endl;
               snake.direction(1);
               break;

            case sf::Keyboard::S:
               std::cout << "S PRESSED" << std::endl;
               snake.direction(2);
               break;

            case sf::Keyboard::A: // left
               std::cout << "A PRESSED" << std::endl;
               snake.direction(3);
               break;

            case sf::Keyboard::Space: // FOR DEBUG
               std::cout << "SPACE PRESSED" << std::endl;
               snake.grow();
               break;
            default:
               break;
            }
         }
      }

      snake.move(snake.direction());

      // check internal collision
      if(snake.checkCollision() != 0)
      {
         sf::sleep(sf::seconds(5));
         return 0;
      }

      // check border
      if(snake.getHeadP().x < 0 || snake.getHeadP().x > windowWidth - pixel
         || snake.getHeadP().y < 0 || snake.getHeadP().y > windowHeight - pixel)
      {
         std::cout << "COLLISION WITH BORDER DETECTED" << std::endl;
         sf::sleep(sf::seconds(5));
         return 0;
      }

      // CHECKING FRUIT COLLISION
      apple.isEaten(snake);
      grape.isEaten(snake);

      // Render
      window.clear(sf::Color::Black);

      snake.draw(window);

      apple.draw(window);
      grape.draw(window);

      window.display();
      sf::sleep(sf::milliseconds(100));
   }
}

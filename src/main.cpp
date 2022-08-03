#include <SFML/Graphics.hpp>
#include "../include/snake.hpp"
#include "../include/fruit.hpp"
#include <iostream> // for debug

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

int main()
{
   sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake", sf::Style::Titlebar);
   window.setFramerateLimit(30);
   window.setKeyRepeatEnabled(false);

   Snake snake;
   Fruit apple(sf::Color::Red);
   apple.generate();

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
      if(snake.getHeadP().x < 0 || snake.getHeadP().x > 800 - 12
         || snake.getHeadP().y < 0 || snake.getHeadP().y > 600 - 12)
      {
         std::cout << "COLLISION WITH BORDER DETECTED" << std::endl;
         sf::sleep(sf::seconds(5));
         return 0;
      }

      // eating a fruit; TODO: THERES A BETTER WAY TO DO THIS like implementin this in fruit::collision
      if(apple.position().x == snake.getHeadP().x && apple.position().y == snake.getHeadP().y)
      {
         apple.generate();
         snake.grow();
      }

      // Render
      window.clear(sf::Color::Black);

      snake.draw(window);
      apple.draw(window);

      window.display();
      sf::sleep(sf::milliseconds(100));
   }
}

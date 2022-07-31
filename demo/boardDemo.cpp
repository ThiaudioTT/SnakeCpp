#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream> // for debug

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

// main will deal with the loop
int main()
{
   sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake", sf::Style::Titlebar); //, sf::Style::Titlebar); // fixed size
   window.setFramerateLimit(60);
  
  // the pivot is in the left superior corner of an object (in case you didn't get it)
  sf::RectangleShape object(sf::Vector2f(50,50));
  object.setPosition(sf::Vector2f(50 * 0, 50 * 0));

  sf::RectangleShape object2(sf::Vector2f(50,50));
  object2.setPosition(sf::Vector2f(50 * 1, 50 * 1));
  object2.setFillColor(sf::Color::Blue);


  sf::RectangleShape object3(sf::Vector2f(50,50));
  object3.setPosition(sf::Vector2f(50 * 2,50 *2));
  object3.setFillColor(sf::Color::Green);

  sf::RectangleShape object4(sf::Vector2f(50,50));
  object4.setPosition(sf::Vector2f(50 * 3, 50 * 3));
  object4.setFillColor(sf::Color::Red);

   while (window.isOpen())
   {
      window.clear(sf::Color::Black);
      window.draw(object);
      window.draw(object2);
      window.draw(object3);
      window.draw(object4);
      window.display();
    
   }
}

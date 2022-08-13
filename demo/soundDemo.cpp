#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> // for debug

void playPop()
{
    sf::SoundBuffer pop;

    if (!pop.loadFromFile("../assets/sound/pop.wav"))
    {
        std::cerr << "POP.WAV EXPECTED" << std::endl;
        throw sf::SoundBuffer{};
    }

    sf::Sound sound;
    sound.setBuffer(pop);
    sound.play();
}


constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

// main will deal with the loop
int main()
{
   sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake", sf::Style::Titlebar); //, sf::Style::Titlebar); // fixed size
   window.setFramerateLimit(60);
  
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../pop.wav"))
        return -1;

   while (window.isOpen())
   {

      window.clear(sf::Color::Black);
      sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
      window.display();
    
   }
}

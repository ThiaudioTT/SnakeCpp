#include "../include/sound.hpp"


Sound::Sound() {
    buffer.loadFromFile("./assets/sound/pop.wav");
}


void Sound::playPop() {
    pop.setBuffer(buffer);
    pop.play();
    std::cout << " player";
}
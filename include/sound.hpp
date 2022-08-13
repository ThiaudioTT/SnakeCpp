#pragma once

#include <SFML/Audio.hpp>
#include <iostream>

/* Notes:
// the sound is relative to the executable file.

sf::soundbuffer and sf::sound need to stay alive while playing
*/


class Sound {
    private:
        sf::SoundBuffer buffer; // generic name for buffer, only pop will use it
        sf::Sound pop;
    
    public:
        Sound();

        // sounds

        /**
         * @brief play pop. Use sf::sound pop and buffer.
         * 
         */
        void playPop();

};
//
// Created by torstein on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_SDLSOUND_H
#define SNAKE_PLUSPLUS_SDLSOUND_H

#include <string>
#include "SDL2/include/SDL_mixer.h"

class SDLSound {
public:
    /* Loads the given file on construction */
    SDLSound(const std::string& file);

    /* Free's the memory consumed by the sound data */
    ~SDLSound();

    /* Play sound effect */
    void playSoundEffect();

private:
    Mix_Chunk *soundEffect;
};


#endif //SNAKE_PLUSPLUS_SDLSOUND_H

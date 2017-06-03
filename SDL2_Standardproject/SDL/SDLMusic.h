//
// Created by torstein on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_SDLMUSIC_H
#define SNAKE_PLUSPLUS_SDLMUSIC_H

#include <string>
#include <SDL_mixer.h>

class SDLMusic {
public:
    /* Loads the given file on construction */
    SDLMusic(const std::string& file);

    /* Free's the memory consumed by the sound data */
    ~SDLMusic();

    /* Play sound effect */
    void playMusic();

    void PauseUnpauseMusic();

    void StopMusic();

private:
    Mix_Music *gameMusic;
};


#endif //SNAKE_PLUSPLUS_SDLMUSIC_H

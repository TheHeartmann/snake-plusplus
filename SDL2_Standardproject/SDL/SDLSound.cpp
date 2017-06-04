//
// Created by torstein on 03.06.17.
//

#include "SDLSound.h"

SDLSound::SDLSound(const std::string &file) {
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	soundEffect = Mix_LoadWAV(file.c_str());
	if (soundEffect == NULL) {
		printf("Could not load soundEffect. SDL_mixer Error: %s\\n", Mix_GetError());
	}
}

void SDLSound::playSoundEffect() {
	Mix_PlayChannel(-1, soundEffect, 0);
}


SDLSound::~SDLSound() {

	//Free the sound effects
	Mix_FreeChunk(soundEffect);
	soundEffect = NULL;

}
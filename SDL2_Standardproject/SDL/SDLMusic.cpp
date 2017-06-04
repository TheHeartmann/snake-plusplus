//
// Created by torstein on 03.06.17.
//

#include "SDLMusic.h"

SDLMusic::SDLMusic(const std::string &file) {
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	gameMusic = Mix_LoadMUS(file.c_str());
	if (gameMusic == NULL) {
		printf("Could not load game music. SDL_mixer Error: %s\\n", Mix_GetError());
	}
}


void SDLMusic::playMusic() {
	Mix_PlayMusic(gameMusic, -1);
}

void SDLMusic::PauseUnpauseMusic() {

	//If there is no music playing
	if (Mix_PlayingMusic() == 0) {
		//Play the music
		Mix_PlayMusic(gameMusic, -1);
	} else //If music is being played
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1) {
			//Resume the music
			Mix_ResumeMusic();
		}
			//If the music is playing
		else {
			//Pause the music
			Mix_PauseMusic();
		}
	}
}

void SDLMusic::StopMusic() {
	Mix_HaltMusic();
}

SDLMusic::~SDLMusic() {
	Mix_FreeMusic(gameMusic);
	gameMusic = NULL;
}
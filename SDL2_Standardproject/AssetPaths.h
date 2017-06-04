//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_ASSETPATHS_H
#define SNAKE_PLUSPLUS_ASSETPATHS_H

#include <string>
using namespace std;

static const struct images {
	images() {}

	const string snakeHead = "SDL2_Standardproject/Assets/gfx/SnakeHead.png";
	const string snakeBody = "SDL2_Standardproject/Assets/gfx/SnakeBody.png";
	const string snakeTail = "SDL2_Standardproject/Assets/gfx/SnakeTail.png";
	const string apple = "SDL2_Standardproject/Assets/gfx/Apple.png";
	const string obstacle = "SDL2_Standardproject/Assets/gfx/Obstacle.png";
	const string wormhole = "SDL2_Standardproject/Assets/gfx/Hole.png";
	const string background = "SDL2_Standardproject/Assets/gfx/SnakeBoard.png";
} images;

static const struct audio {
	audio() {}

	const string level = "SDL2_Standardproject/Assets/sfx/musicLoop.wav";
	const string crunch = "SDL2_Standardproject/Assets/sfx/eating.wav";
	const string grunt = "SDL2_Standardproject/Assets/sfx/grunt.wav";
	const string wormhole = "SDL2_Standardproject/Assets/sfx/bonus.wav";
} audio;

#endif //SNAKE_PLUSPLUS_ASSETPATHS_H

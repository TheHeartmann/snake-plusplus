//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_BACKGROUNDRENDERER_H
#define SNAKE_PLUSPLUS_BACKGROUNDRENDERER_H


#include "Renderer.h"

class BackgroundRenderer : public Renderer {
public:
	BackgroundRenderer(SDLPng &background) : background(background) {}

	virtual void render() const override;
private:
	SDLPng &background;
};


#endif //SNAKE_PLUSPLUS_BACKGROUNDRENDERER_H

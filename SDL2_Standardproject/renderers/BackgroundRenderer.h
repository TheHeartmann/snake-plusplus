//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_BACKGROUNDRENDERER_H
#define SNAKE_PLUSPLUS_BACKGROUNDRENDERER_H


#include "Renderer.h"

class BackgroundRenderer : public Renderer {
public:
	BackgroundRenderer(shared_ptr<SDLPng> &background) : background(background) {}

	BackgroundRenderer(const string path) : background(make_shared<SDLPng>(path)){}

	BackgroundRenderer(){
		background = make_shared<SDLPng>();
	};

	virtual void render() override;
private:
	shared_ptr<SDLPng> background;
};


#endif //SNAKE_PLUSPLUS_BACKGROUNDRENDERER_H

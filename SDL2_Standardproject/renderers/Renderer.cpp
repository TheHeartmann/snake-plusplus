//
// Created by thomas on 04.06.17.
//

#include <iostream>
#include "Renderer.h"

void Renderer::setPosition(const Node &node, SDLPng &image) const {
	image.setPositionGridwise(node.grid_x, node.grid_y);
}

void Renderer::render(SDLPng &image) const {
	image.draw();
}

void Renderer::render(SDLPng &image, const Direction direction) const {
	image.draw(static_cast<int>(direction));
}

void Renderer::setPosAndRender(const Node &node, SDLPng &image) const {
	setPosition(node, image);
	render(image);
}

void Renderer::setPosAndRender(const Node &node, SDLPng &image, const Direction direction) const {
	setPosition(node, image);
	render(image, direction);
}
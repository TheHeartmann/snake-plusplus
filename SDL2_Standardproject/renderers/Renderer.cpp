//
// Created by thomas on 04.06.17.
//

#include <gameObjects/GameObject.h>
#include "Renderer.h"

void Renderer::setPosition(const Node &node, SDLBmp &image) const {
	image.setPositionGridwise(node.grid_x, node.grid_y);
}

void Renderer::render(SDLBmp &image) const {
	image.draw();
}

void Renderer::render(SDLBmp &image, const Direction direction) const {
	image.draw(static_cast<int>(direction));
}

void Renderer::setPosAndRender(const Node &node, SDLBmp &image) const {
	setPosition(node, image);
	render(image);
}

void Renderer::setPosAndRender(const Node &node, SDLBmp &image, const Direction direction) const {
	setPosition(node, image);
	render(image, direction);
}
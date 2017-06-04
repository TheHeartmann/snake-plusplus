//
// Created by thomas on 04.06.17.
//

#include "Renderer.h"

void Renderer::setPosition(const Node &node, SDLBmp &image) const {
	image.setPositionGridwise(node.grid_x, node.grid_y);
}

void Renderer::render(SDLBmp &image) const {
	image.draw();
}

void Renderer::setPosAndRender(const Node &node, SDLBmp &image) const {
	setPosition(node, image);
	render(image);
}
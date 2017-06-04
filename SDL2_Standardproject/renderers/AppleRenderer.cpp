//
// Created by thomas on 03.06.17.
//

#include "AppleRenderer.h"

void AppleRenderer::renderApple(Node &node) const {
	setPosAndRender(node, *apple);
}

void AppleRenderer::render() const {
	renderApple(appleNode);
}

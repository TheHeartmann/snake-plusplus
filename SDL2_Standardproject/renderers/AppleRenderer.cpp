//
// Created by thomas on 03.06.17.
//

#include "AppleRenderer.h"

void AppleRenderer::renderApple(Node &node) {
	setPosAndRender(node, *apple);
}

void AppleRenderer::render() {
	renderApple(appleNode);
}

AppleRenderer::AppleRenderer(const string path, Node &appleNode)
		: apple(make_shared<SDLPng>(path)), appleNode(appleNode) {}
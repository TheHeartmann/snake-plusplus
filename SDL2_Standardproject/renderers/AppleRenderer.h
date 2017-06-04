//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_APPLERENDERER_H
#define SNAKE_PLUSPLUS_APPLERENDERER_H


#include "Renderer.h"

class AppleRenderer : public Renderer {
public:
	AppleRenderer(const string path, Node &appleNode);

	AppleRenderer(SDLPng &apple, Node &appleNode)
			: apple(apple), appleNode(appleNode) {}

	void renderApple(Node &node);
	virtual void render() override;
private:
	SDLPng apple;
	Node &appleNode;
};

#endif //SNAKE_PLUSPLUS_APPLERENDERER_H

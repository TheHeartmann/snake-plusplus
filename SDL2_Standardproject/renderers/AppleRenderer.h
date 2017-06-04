//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_APPLERENDERER_H
#define SNAKE_PLUSPLUS_APPLERENDERER_H


#include "Renderer.h"

class AppleRenderer : public Renderer {
public:
//	AppleRenderer(const shared_ptr<SDLPng> &apple)
//			: apple(apple), appleNode() {}

	AppleRenderer(const shared_ptr<SDLPng> &apple, Node &appleNode)
			: apple(apple), appleNode(appleNode) {}

	void renderApple(Node &node) const;
	virtual void render() const override;
private:
	std::shared_ptr<SDLPng> apple;
	Node &appleNode;
};

#endif //SNAKE_PLUSPLUS_APPLERENDERER_H

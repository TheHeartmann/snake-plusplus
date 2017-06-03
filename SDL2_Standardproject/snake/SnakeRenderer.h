//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_SNAKERENDERER_H
#define SNAKE_PLUSPLUS_SNAKERENDERER_H


#include <SDL/SDLBmp.h>
#include "Snake_new.h"
#include <memory>

class SnakeRenderer {
public:
	SnakeRenderer(const shared_ptr<SDLBmp> &head, const shared_ptr<SDLBmp> &body) : head(head), body(body) {}

	void render(Snake_new &snake);
private:
	std::shared_ptr<SDLBmp> head;
	std::shared_ptr<SDLBmp> body;
	void drawHead(const Node &head) const;
	void renderBody(list <Node> &positions) const;
};


#endif //SNAKE_PLUSPLUS_SNAKERENDERER_H

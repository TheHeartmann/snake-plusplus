//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_SNAKERENDERER_H
#define SNAKE_PLUSPLUS_SNAKERENDERER_H


#include <SDL/SDLBmp.h>
#include "snake/Snake_new.h"
#include "Renderer.h"
#include <memory>

class SnakeRenderer : Renderer {
public:
	SnakeRenderer(const shared_ptr<SDLBmp> &head, const shared_ptr<SDLBmp> &body) : head(head), body(body) {}
	void render(Snake_new &snake);
private:
	std::shared_ptr<SDLBmp> head;
	std::shared_ptr<SDLBmp> body;
	std::shared_ptr<SDLBmp> tail;
	void renderHead(const Node &head) const;
	void renderBody(const list <Node> &bodyList) const;
	void renderTail(const Node& tail) const;
};


#endif //SNAKE_PLUSPLUS_SNAKERENDERER_H

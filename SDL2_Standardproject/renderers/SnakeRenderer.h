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
private:
	virtual void render() override;
public:
	SnakeRenderer(const shared_ptr<SDLBmp> &head, const shared_ptr<SDLBmp> &body) : head(head), body(body) {}
	void render(const Snake_new &snake, const Direction direction);
private:
	std::shared_ptr<SDLBmp> head;
	std::shared_ptr<SDLBmp> body;
	std::shared_ptr<SDLBmp> tail;
	void renderHead(const Node &headNode, const Direction direction) const;
	void renderBody(const list <Node> &bodyList, Direction heading) const;
	void renderTail(const Node& tailNode) const;
};


#endif //SNAKE_PLUSPLUS_SNAKERENDERER_H

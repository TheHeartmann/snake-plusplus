//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_SNAKERENDERER_H
#define SNAKE_PLUSPLUS_SNAKERENDERER_H


#include "snake/Snake.h"
#include "Renderer.h"

class SnakeRenderer : public Renderer {
public:
	virtual void render() override;
public:
	SnakeRenderer(const string headPath, const string bodyPath,
	              const string tailPath, const Snake &snake,
	              const Direction &heading);

	SnakeRenderer(shared_ptr<SDLPng> head, shared_ptr<SDLPng> body, shared_ptr<SDLPng> tail,
	              Snake &snake, Direction &heading)
			: head(head), body(body), tail(tail), snake(snake), heading(heading) {}

	void render(const Snake &snake, const Direction heading);
private:
	shared_ptr<SDLPng> head;
	shared_ptr<SDLPng> body;
	shared_ptr<SDLPng> tail;

	Snake const &snake;
	Direction const &heading;

	void renderHead(const Node &headNode, const Direction heading) ;
	void renderBody(const list <Node> &bodyList, Direction heading) ;
	void renderTail(const Node &tailNode, Direction heading);
};


#endif //SNAKE_PLUSPLUS_SNAKERENDERER_H

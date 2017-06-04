//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_SNAKERENDERER_H
#define SNAKE_PLUSPLUS_SNAKERENDERER_H


#include "snake/Snake_new.h"
#include "Renderer.h"
#include <memory>

class SnakeRenderer : public Renderer {
public:
	virtual void render() override;
public:
	SnakeRenderer(const string headPath, const string bodyPath,
	              const string tailPath, const Snake_new &snake,
	              const Direction &heading);

	SnakeRenderer(SDLPng &head, SDLPng &body, SDLPng &tail,
	              Snake_new &snake, Direction &heading)
			: head(head), body(body), tail{tail}, snake(snake), heading(heading) {}

	void render(const Snake_new &snake, const Direction heading);
private:
	SDLPng head;
	SDLPng body;
	SDLPng tail;

	Snake_new const &snake;
	Direction const &heading;

	void renderHead(const Node &headNode, const Direction heading) ;
	void renderBody(const list <Node> &bodyList, Direction heading) ;
	void renderTail(const Node &tailNode, Direction heading);
};


#endif //SNAKE_PLUSPLUS_SNAKERENDERER_H

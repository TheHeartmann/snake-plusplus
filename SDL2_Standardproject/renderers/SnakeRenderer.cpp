//
// Created by thomas on 03.06.17.
//

#include "SnakeRenderer.h"

void SnakeRenderer::render(const Snake &snake, const Direction direction) {
	auto body = snake.getBody();

	renderHead(snake.getHead(), direction);

	renderBody(body, direction);

	auto it = body.end();
	auto directionVec = *(std::prev(it, 1)) - *(std::prev(it, 2));
	renderTail(snake.getTail(), directionVec.getDirection());
}

void SnakeRenderer::renderBody(const list <Node> &bodyList, Direction heading) {
	auto snakeBody = bodyList;
	snakeBody.pop_back(); snakeBody.pop_front(); // remove head and tail
	renderListLinked(snakeBody, *body, heading);
}

void SnakeRenderer::renderHead(const Node &headNode, const Direction direction) {
	setPosAndRender(headNode, *head, direction);
}

void SnakeRenderer::renderTail(const Node &tailNode, Direction direction) {
	setPosAndRender(tailNode, *tail, direction);
}


void SnakeRenderer::render() {
	render(snake, heading);
}

SnakeRenderer::SnakeRenderer(const string headPath, const string bodyPath,
                             const string tailPath, const Snake &snake,
                             const Direction &heading)
		: head(make_shared<SDLPng>(headPath)), body(make_shared<SDLPng>(bodyPath)),
		  tail(make_shared<SDLPng>(tailPath)), snake(snake), heading(heading) {}

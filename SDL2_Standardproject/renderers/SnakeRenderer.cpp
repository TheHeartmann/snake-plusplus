//
// Created by thomas on 03.06.17.
//

#include "SnakeRenderer.h"

void SnakeRenderer::render(const Snake_new &snake, const Direction direction) {
	renderHead(snake.getHead(), direction);
	renderBody(snake.getBody(), direction);
//	renderTail(snake.getTail());
}

void SnakeRenderer::renderBody(const list <Node> &bodyList, Direction heading) const {
	auto snakeBody = bodyList;
	snakeBody.pop_back(); snakeBody.pop_front(); // remove head and tail
	renderListLinked(snakeBody, *body, heading);
}

void SnakeRenderer::renderHead(const Node &headNode, const Direction direction) const {
	setPosAndRender(headNode, *head, direction);
}

void SnakeRenderer::renderTail(const Node &tailNode) const {
	setPosAndRender(tailNode, *tail);
}

void SnakeRenderer::render() {

}

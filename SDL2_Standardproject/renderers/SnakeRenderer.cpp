//
// Created by thomas on 03.06.17.
//

#include "SnakeRenderer.h"

void SnakeRenderer::render(const Snake_new &snake) {
	auto snakeBody = snake.getBody();
	auto headNode = snake.getHead();
	auto tailNode = snake.getTail();
	snakeBody.pop_back(); snakeBody.pop_front();
	renderHead(snake.getHead());
//	renderTail(snake.getTail());
	renderList(snakeBody, *body);
}

void SnakeRenderer::renderBody(const list <Node> &bodyList) const {
	auto it = bodyList.begin();
	while (++it != bodyList.end()){
		setPosAndRender(*it, *body);
	}
}

void SnakeRenderer::renderHead(const Node &snakeHead) const {
	setPosAndRender(snakeHead, *head);
}

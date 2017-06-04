//
// Created by thomas on 03.06.17.
//

#include "SnakeRenderer.h"

void SnakeRenderer::render(Snake_new &snake) {
	renderHead(snake.getHead());
	renderBody(snake.getBody());
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

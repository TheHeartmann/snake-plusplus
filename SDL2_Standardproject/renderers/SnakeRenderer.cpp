//
// Created by thomas on 03.06.17.
//

#include "SnakeRenderer.h"

void SnakeRenderer::render(Snake_new &snake) {
	renderHead(snake.getHead());

	auto positions = snake.getBody();
	renderBody(positions);
}

void SnakeRenderer::renderBody(list <Node> &bodyList) const {
	auto it = bodyList.begin();
	while (++it != bodyList.end()){
		auto node = *it;
		body->setPositionGridwise(node.grid_x, node.grid_y);
		body->draw();
	}
}

void SnakeRenderer::renderHead(const Node &snakeHead) const {
	SnakeRenderer::head->setPositionGridwise(snakeHead.grid_x, snakeHead.grid_y);
	SnakeRenderer::head->draw();
}

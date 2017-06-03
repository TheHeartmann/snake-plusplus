//
// Created by thomas on 03.06.17.
//

#include "SnakeRenderer.h"

void SnakeRenderer::render(Snake_new &snake) {
	drawHead(snake.getHead());

	auto positions = snake.getBody();
	auto it = positions.begin();
	std::next(it); // skip the head
	renderBody(positions);
}

void SnakeRenderer::renderBody(list <Node> &positions) const {
	auto it = positions.begin();
	while (++it != positions.end()){
		auto node = *it;
		body->setPositionGridwise(node.grid_x, node.grid_y);
		body->draw();
	}
}

void SnakeRenderer::drawHead(const Node &snakeHead) const {
	SnakeRenderer::head->setPositionGridwise(snakeHead.grid_x, snakeHead.grid_y);
	SnakeRenderer::head->draw();
}

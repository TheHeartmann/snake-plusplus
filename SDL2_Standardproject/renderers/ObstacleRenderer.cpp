//
// Created by thomas on 03.06.17.
//

#include "ObstacleRenderer.h"

void ObstacleRenderer::renderObstacles(const vector<Node> nodeList) {
	for (auto &&node :nodeList) {
		obstacle->setPositionGridwise(node.grid_x, node.grid_y);
		obstacle->draw();
	}
}

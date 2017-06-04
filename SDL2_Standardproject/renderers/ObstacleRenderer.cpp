//
// Created by thomas on 03.06.17.
//

#include "ObstacleRenderer.h"

void ObstacleRenderer::renderObstacles(const vector<Node> nodeList) {
	for (auto &&node :nodeList) {
		setPosAndRender(node, *obstacle);
	}
}

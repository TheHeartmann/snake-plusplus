//
// Created by thomas on 03.06.17.
//

#include "ObstacleRenderer.h"

void ObstacleRenderer::renderObstacles(const vector<Node> nodeList) {
	if (nodeList.size() == 0) return;
	renderList(nodeList, *obstacle);
}

void ObstacleRenderer::render() {

}

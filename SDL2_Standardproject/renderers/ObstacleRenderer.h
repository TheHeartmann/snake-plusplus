//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_OBSTACLERENDERER_H
#define SNAKE_PLUSPLUS_OBSTACLERENDERER_H


#include <memory>
#include <vector>
#include "Renderer.h"

class ObstacleRenderer : public Renderer {
public:
	ObstacleRenderer(const string path, vector<Node> &obstacleList)
			: obstacle{SDLPng(path)}, obstacleList(obstacleList) {}

	ObstacleRenderer(SDLPng &obstacle, vector<Node> &obstacleList)
			: obstacle(obstacle), obstacleList(obstacleList) {}

	template<typename C>
	void renderObstacles(const C &nodeList) const;
	virtual void render() override;
private:
	SDLPng obstacle;
	vector<Node> &obstacleList;
};

template<typename C>
void ObstacleRenderer::renderObstacles(const C &nodeList) const {
	if (nodeList.size() == 0) return;
	auto obstacleCopy = obstacle;
	renderList(nodeList, obstacleCopy);
}


#endif //SNAKE_PLUSPLUS_OBSTACLERENDERER_H

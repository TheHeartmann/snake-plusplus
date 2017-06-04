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
//	ObstacleRenderer(const shared_ptr<SDLPng> &obstacle)
//			: obstacle(obstacle), obstacleList() {}

	ObstacleRenderer(const shared_ptr<SDLPng> &obstacle, vector<Node> &obstacleList)
			: obstacle(obstacle), obstacleList(obstacleList) {}

	template<typename C>
	void renderObstacles(const C &nodeList) const;
	virtual void render() const override;
private:
	std::shared_ptr<SDLPng> obstacle;
	vector<Node> &obstacleList;
};

template<typename C>
void ObstacleRenderer::renderObstacles(const C &nodeList) const {
	if (nodeList.size() == 0) return;
	renderList(nodeList, *obstacle);
}


#endif //SNAKE_PLUSPLUS_OBSTACLERENDERER_H

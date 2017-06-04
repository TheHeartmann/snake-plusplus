//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_OBSTACLERENDERER_H
#define SNAKE_PLUSPLUS_OBSTACLERENDERER_H


#include <vector>
#include "Renderer.h"

class ObstacleRenderer : public Renderer {
public:
	ObstacleRenderer(const string path, vector<Node> &obstacleList)
			: obstacle(make_shared<SDLPng>(path)), obstacleList(obstacleList) {}

	ObstacleRenderer(shared_ptr<SDLPng> &obstacle, vector<Node> &obstacleList)
			: obstacle(obstacle), obstacleList(obstacleList) {}

	template <typename C>
	void renderObstacles(C && nodeList) const;

	virtual void render() override;
private:
	shared_ptr<SDLPng> obstacle;
	vector<Node> &obstacleList;
};

template<typename C>
void ObstacleRenderer::renderObstacles(C &&nodeList) const {
	if (nodeList.size() == 0) return;
	renderList(nodeList, *obstacle);
}

#endif //SNAKE_PLUSPLUS_OBSTACLERENDERER_H

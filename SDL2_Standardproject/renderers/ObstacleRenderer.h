//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_OBSTACLERENDERER_H
#define SNAKE_PLUSPLUS_OBSTACLERENDERER_H


#include <SDL/SDLBmp.h>
#include <memory>
#include <vector>
#include "Renderer.h"

class ObstacleRenderer : public Renderer {
public:
	ObstacleRenderer(const shared_ptr<SDLBmp> &obstacle) : obstacle(obstacle) {}
	void renderObstacles(const vector<Node> nodeList);
	virtual void render() override;
private:
	std::shared_ptr<SDLBmp> obstacle;
};

#endif //SNAKE_PLUSPLUS_OBSTACLERENDERER_H

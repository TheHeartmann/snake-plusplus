//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_RENDERERMANAGER_H
#define SNAKE_PLUSPLUS_RENDERERMANAGER_H


#include <renderers/Renderer.h>
#include <vector>
#include <renderers/BackgroundRenderer.h>

class RendererManager {
public:
	RendererManager() {}

	RendererManager(BackgroundRenderer &backgroundRenderer, const vector<shared_ptr<Renderer>> renderers)
			: backgroundRenderer(backgroundRenderer), objectRenderers(renderers) {}

	void renderAll();
private:
	BackgroundRenderer backgroundRenderer;
	vector<shared_ptr<Renderer>> objectRenderers{};
};


#endif //SNAKE_PLUSPLUS_RENDERERMANAGER_H

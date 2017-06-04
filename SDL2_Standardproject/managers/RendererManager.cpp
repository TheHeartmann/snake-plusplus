//
// Created by thomas on 04.06.17.
//

#include "RendererManager.h"

void RendererManager::renderAll() {
	backgroundRenderer.render();
	for (auto &&renderer  : objectRenderers) {
		renderer->render();
	}
}

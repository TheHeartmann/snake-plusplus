//
// Created by thomas on 03.06.17.
//

#ifndef SNAKE_PLUSPLUS_OBJECTLISTRENDERER_H
#define SNAKE_PLUSPLUS_OBJECTLISTRENDERER_H


#include <vector>
#include "Renderer.h"

class ObjectListRenderer : public Renderer {
public:
	ObjectListRenderer(const string path, vector<Node> &objectList)
			: object(make_shared<SDLPng>(path)), objectList(objectList) {}

	ObjectListRenderer(shared_ptr<SDLPng> &object, vector<Node> &objectList)
			: object(object), objectList(objectList) {}

	template <typename C>
	void renderObjects(C &&nodeList) const;

	virtual void render() override;
private:
	shared_ptr<SDLPng> object;
	vector<Node> &objectList;
};

template<typename C>
void ObjectListRenderer::renderObjects(C &&nodeList) const {
	if (nodeList.size() == 0) return;
	renderList(nodeList, *object);
}

#endif //SNAKE_PLUSPLUS_OBJECTLISTRENDERER_H

//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_RENDERER_H
#define SNAKE_PLUSPLUS_RENDERER_H


#include <board/Node.h>
#include <SDL/SDLPng.h>

class Renderer {
public:
	virtual void render()= 0;
protected:
	void setPosition(const Node &node, SDLPng& image) const;
	void render(SDLPng& image) const;
	void render(SDLPng &image, const Direction direction) const;
	void setPosAndRender(const Node &node, SDLPng& image) const;
	void setPosAndRender(const Node &node, SDLPng &image, const Direction direction) const;
	template <typename C>
	void renderList(C&& nodes, SDLPng& image) const;
	template <typename C>
	void renderListLinked(C &&nodes, SDLPng &image, Direction firstDirection) const;
};

template<typename C>
void Renderer::renderList(C &&nodes, SDLPng &image) const {
	for (auto &node :nodes) {
		setPosAndRender(node, image);
	}
}


template<typename C>
void Renderer::renderListLinked(C &&nodes, SDLPng &image, Direction firstDirection) const {
	Node currentNode, previousNode;
	auto directionVec = Vector2D{firstDirection}; //set first direction

	auto it = nodes.begin();
	previousNode = *it;
	setPosAndRender(previousNode, image, firstDirection);
	it++;

	while (it != nodes.end()){
		currentNode = *it;
		directionVec = previousNode - currentNode;
		setPosAndRender(currentNode, image, directionVec.getDirection());
		previousNode = currentNode;
		it++;
	}
}

#endif //SNAKE_PLUSPLUS_RENDERER_H

//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_RENDERER_H
#define SNAKE_PLUSPLUS_RENDERER_H


#include <board/Node.h>
#include <SDL/SDLBmp.h>

class Renderer {
protected:
	void setPosition(const Node &node, SDLBmp& image) const;
	void render(SDLBmp& image) const;
	void setPosAndRender(const Node &node, SDLBmp& image) const;
	template <typename C>
	void renderList(C&& nodes, SDLBmp& image);
};

template<typename C>
void Renderer::renderList(C &&nodes, SDLBmp &image) {
	for (auto &node :nodes) {
		setPosAndRender(node, image);
	}
}

#endif //SNAKE_PLUSPLUS_RENDERER_H

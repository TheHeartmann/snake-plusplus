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
};


#endif //SNAKE_PLUSPLUS_RENDERER_H

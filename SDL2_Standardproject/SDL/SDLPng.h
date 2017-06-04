/*
 * @file: SDLPng.cpp
 * @author: Torstein Alvern
 * @version: 1.0.1 <03.06.2017>
 *
 * @description: A class that makes it easy to load,
 *				 display and work with png images, based on SDLBmp written by Stig M. Halvorsen
 */


#ifndef SNAKE_PLUSPLUS_SDLPNG_H
#define SNAKE_PLUSPLUS_SDLPNG_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <board/Node.h>

class SDLPng
{
public:
    /* Loads the given file on construction */
    SDLPng(const std::string& file);

    SDLPng();

    /* Free's the memory consumed by the image data */
    ~SDLPng();

    /* Adds the image to the master window */
    void draw();
    void draw (int rotation);

    /* Getters for image height and width*/
    int getWidth () const;
    int getHeight () const;

    inline void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    inline void setPositionGridwise(int gridX, int gridY) {
        x = gridX * 20;
        y = gridY * 20;
    }

    /* "home brewed" float coordinates, SDL2 uses ints
        which is a bit too unpresice. */
    float x;
    float y;
private:
    SDL_Texture* m_texture; // Pixel data (on GPU)
    SDL_Renderer* m_renderer; // Pointer to window's renderer.
    SDL_Rect m_rect; // Used for w/h, placement and cropping.
};

#endif //SNAKE_PLUSPLUS_SDLPNG_H

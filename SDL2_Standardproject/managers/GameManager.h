/*
 * @file: GameManager.h
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "SDL/SDLManager.h"
#include "SDL/SDLBmp.h"
#include "InputManager.h"
#include "resourceManagement/Timer.h"
#include "gameObjects/GameObject.h"
#include "snake/Snake.h"

class GameManager {
public:
    /* Meyer's singleton style instance call */
    static GameManager &Instance() {
        static GameManager g;
        return g;
    }

    /* Kicks off/is the the gameloop */
    void play();


private:

    GameManager();                                // Hidden constructor
    GameManager(const GameManager &);            // Hidden copy constructor
    GameManager &operator=(const GameManager &); // Hidden assign operator
    void updateDirection(Direction &direction);

    bool isOutOfBounds(GameObject &player);

    void AutoCannibalismCheck(Snake *player);

    /*Point2D getRandomPoint(GameObject* image, int boardWidth, int boardHeight);*/
    Point2D getRandomPoint();

    static bool CrashedWithObjectCheck(GameObject *player, GameObject *object);

    void init();

    void loadAssets();

    void drawGrid(Node **grid, int x, int y, SDL_Renderer &renderer);


    bool running = true;
    unsigned int m_window; // pointer to main window
    float m_lastRender; // Time in seconds since last render
    const int board_width = Specs.BOARD_WIDTH;
    const int board_height = Specs.BOARD_HEIGHT;
    const int node_radius = Specs.NODE_RADIUS;
    const int node_diameter = Specs.NODE_DIAMETER;
    const float acceleration = Specs.SNAKE_ACCELERATION;

    float speed = Specs.SNAKE_SPEED;

    std::unique_ptr<SDLBmp> background;

    std::shared_ptr<SDLBmp> playerHeadImage;
    std::shared_ptr<SDLBmp> playerBodyImage;
    std::shared_ptr<SDLBmp> appleImage;
};

#endif
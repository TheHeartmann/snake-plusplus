/*
 * @file: GameManager.h
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <board/GameBoard.h>
#include <snake/Snake_new.h>
#include <SDL/SDLPng.h>
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

    static bool hitObject(GameObject *player, GameObject *object);

    void init();

    void loadAssets();

    void drawGrid(int x, int y, SDL_Renderer &renderer);


    bool running = true;
    unsigned int m_window; // pointer to main window
    float m_lastRender; // Time in seconds since last render
    const int board_width = Specs.BOARD_RENDER_WIDTH_PX;
    const int board_height = Specs.BOARD_RENDER_HEIGHT_PX;
    const int board_columns = Specs.BOARD_COLUMNS;
    const int board_rows = Specs.BOARD_ROWS;
    const int node_radius = Specs.NODE_RADIUS_PX;
    const int node_diameter = Specs.NODE_DIAMETER_PX;
    const double acceleration = Specs.SNAKE_ACCELERATION;

    double velocity = Specs.SNAKE_SPEED;

    shared_ptr<GameBoard> gameboard;
    shared_ptr<Snake_new> snake_new;

    std::unique_ptr<SDLPng> background;

    std::shared_ptr<SDLBmp> playerHeadImage;
    std::shared_ptr<SDLBmp> playerBodyImage;
    std::shared_ptr<SDLBmp> appleImage;

};

#endif
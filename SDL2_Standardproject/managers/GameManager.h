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
#include "SDL/SDLManager.h"
#include "SDL/SDLBmp.h"
#include "InputManager.h"
#include "resourceManagement/Timer.h"
#include "snake/Snake.h"
#include <renderers/SnakeRenderer.h>
#include "Direction.h"

class GameManager {
public:
    /* Meyer's singleton style instance call */
    static GameManager &Instance() {
        static GameManager g;
        return g;
    }

    /* Kicks off/is the the gameloop */
    void play();

    template<typename Container>
    bool contains(Container list, const Node& elem);


private:

    GameManager();                                // Hidden constructor
    GameManager(const GameManager &);            // Hidden copy constructor
    GameManager &operator=(const GameManager &); // Hidden assign operator
    void updateDirection(Direction &currentDirection, Direction &nextDirection);

    void init();

    void loadAssets();

    void drawGrid(int x, int y, SDL_Renderer &renderer);


    bool running = true;
    unsigned int m_window; // pointer to main window
    float m_lastRender; // Time in seconds since last render
    float m_lastMove; // Time in seconds since last position update

    Direction direction = Specs.SNAKE_HEAD_STARTDIR;
    const int board_width = Specs.BOARD_RENDER_WIDTH_PX;
    const int board_height = Specs.BOARD_RENDER_HEIGHT_PX;
    const int board_columns = Specs.BOARD_COLUMNS;
    const int board_rows = Specs.BOARD_ROWS;
    const int node_radius = Specs.NODE_RADIUS_PX;
    const int node_diameter = Specs.NODE_DIAMETER_PX;
    const double acceleration = Specs.SNAKE_ACCELERATION;

    int score = 0;
    double velocity = Specs.SNAKE_SPEED;
    Vector2D velocityVec{0,0};

    vector<Node> obstacles{};
    shared_ptr<GameBoard> gameboard;
    shared_ptr<Snake_new> snake_new;
    Node appleNode{};

    std::unique_ptr<SDLBmp> background;

    std::shared_ptr<SDLBmp> playerHeadImage;
    std::shared_ptr<SDLBmp> playerBodyImage;
    std::shared_ptr<SDLBmp> appleImage;

    Vector2D getVelocityVector(Direction direction);

    bool isOutOfBounds(const Node &node) const;

    void updateBoard();

    bool isObstacle(const Node &node) const;

    bool isApple(const Node &nextPos) const;

    void getValidPosition(Node &obj);

    Node getRandomNode();

    bool isEmptyNode(const Node &node) const;

    bool isSnake(const Node &node) const;

    Node getSnakeHeadNextPos(Node &head, Vector2D &velocity);

    bool isTooCloseToSnake(const Node &node) const;

    int scoreDelta = 0;

    void playAppleSound();
    Direction getNextDirection(Direction &currentDirection);
};

#endif
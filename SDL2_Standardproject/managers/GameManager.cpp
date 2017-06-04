/*
 * @file: GameManager.cpp
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#include "GameManager.h"
#include <iostream>
#include <algorithm>
#include <renderers/AppleRenderer.h>
#include <renderers/ObstacleRenderer.h>

using namespace std;

/* Initializes SDL, creates the game window and fires off the timer. */
GameManager::GameManager() {
    SDLManager::Instance().init();
    m_window = SDLManager::Instance().createWindow("My Awesome SDL 2.0 Game");
    Timer::Instance().init();
}


void GameManager::loadAssets() {
    // Load images
    background = std::make_unique<SDLPng>("SDL2_Standardproject/Assets/gfx/SnakeBoard.png");
    playerHeadImage = std::make_shared<SDLPng>("SDL2_Standardproject/Assets/gfx/SnakeHead.png");
    playerBodyImage = std::make_shared<SDLPng>("SDL2_Standardproject/Assets/gfx/SnakeBody.png");
    playerTailImage = std::make_shared<SDLPng>("SDL2_Standardproject/Assets/gfx/SnakeTail.png");
    appleImage = std::make_shared<SDLPng>("SDL2_Standardproject/Assets/gfx/Apple.png");
    obstacleImage = std::make_shared<SDLPng>("SDL2_Standardproject/Assets/gfx/Obstacle.png");

    // Load sounds
    gameMusic = std::make_unique<SDLMusic>("SDL2_Standardproject/Assets/sfx/musicLoop.wav");
    appleSound = std::make_shared<SDLSound>("SDL2_Standardproject/Assets/sfx/eating.wav");
    gruntSound = std::make_shared<SDLSound>("SDL2_Standardproject/Assets/sfx/grunt.wav");
    bonusSound = std::make_shared<SDLSound>("SDL2_Standardproject/Assets/sfx/bonus.wav");
}

void GameManager::init() {
    // set up game

    // get 4 joint nodes from the board
    Node head{15, 12};
    Node body1{15, 11};
    Node body2{15, 10};
    Node body3{15, 9};
    Node body4{15, 8};

    list <Node> startBody{head, body1, body2, body3, body4};

    velocityVec = getVelocityVector(Direction::DOWN);
    snake_new = std::make_shared<Snake_new>(startBody);
    getValidPosition(appleNode);

    gameMusic->playMusic();
}


/* Kicks off/is the the gameloop */
void GameManager::play() {

    loadAssets();
    init();
    auto snakeRenderer = SnakeRenderer{playerHeadImage, playerBodyImage, playerTailImage};
    auto appleRenderer = AppleRenderer{appleImage};
    auto obstacleRenderer = ObstacleRenderer{obstacleImage};

    // Calculate render frames per second (second / frames) (60)
    float render_fps = 1.f / 60.f;
    m_lastRender = render_fps; // set it to render immediately

    m_lastMove = move_update_rate;

    Direction nextDirection = direction;

    // Gameloop
    while (running) {

        //Input
        // Update input and deltatime
        InputManager::Instance().Update();

        // Exit on [Esc], or window close (user X-ed out the window)
        if (InputManager::Instance().hasExit() || InputManager::Instance().KeyDown(SDL_SCANCODE_ESCAPE)) {
            running = false;
            break;
        } else {
            // Input Management
            updateDirection(direction, nextDirection);
        }


        Timer::Instance().update();
        m_time_delta = Timer::Instance().deltaTime();

        //the logic frames
        m_lastMove += m_time_delta;
        apple_spawn_time += m_time_delta;

        if (m_lastMove >= move_update_rate) {
            direction = nextDirection;
            update_game_state();
            m_lastMove = 0.f;
        }


        //Render
        // Update time since last render
        m_lastRender += m_time_delta;

        // Check if it's time to render
        if (m_lastRender >= render_fps) {
            // Add bitmaps to renderer
            background->draw();
            snakeRenderer.render(*snake_new, direction);
            appleRenderer.renderApple(appleNode);
            obstacleRenderer.renderObstacles(obstaclesVector);
            // Render window
            SDLManager::Instance().renderWindow(m_window);
            m_lastRender = 0.f;
        }

        // Sleep to prevent CPU exhaustion (1ms == 1000 frames per second)
        SDL_Delay(1);
    }

}

void GameManager::update_game_state() {
    velocityVec = getVelocityVector(direction);
    auto snakeHead = snake_new->getHead();
    Node nextPos = getSnakeHeadNextPos(snakeHead, velocityVec);

    if (isOutOfBounds(nextPos) || snakeCrashesWith(nextPos)) {
        running = false;
        return;
    }


    if (isApple(nextPos)) {
        snake_new->grow(nextPos);
        respawnApple();

        increaseSpeed(move_update_rate);
        playAppleSound();
        score++;
        scoreDelta++;
    } else {
        snake_new->move(nextPos);
    }

    if (apple_spawn_time >= apple_spawn_time_delta) {
        respawnApple();
    }


    if (snake_new->getLength() >= (board_columns * board_rows - obstaclesVector.size())) {
        running = false;
        return;
    }

    //create a new obstacle
    if (scoreDelta >= Specs.OBSTACLE_SPAWN_RATE) {
        Node newObstacle;
        getValidPosition(newObstacle);
        obstaclesVector.push_back(newObstacle);


        scoreDelta = 0;
    }

}

void GameManager::respawnApple() {
    getValidPosition(appleNode);
    apple_spawn_time_delta = Specs.MIN_APPLE_RESPAWN_TIME + rand() % Specs.APPLESPAWN_TIME_DELTA;
    apple_spawn_time = 0;
}


//Checks input and sets direction
void GameManager::updateDirection(Direction &currentDirection, Direction &nextDirection) {

    // Left key
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_LEFT) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_LEFT)) && currentDirection != Direction::RIGHT) {
        nextDirection = Direction::LEFT;
    }

    // Right key
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_RIGHT) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_RIGHT)) && currentDirection != Direction::LEFT) {
        nextDirection = Direction::RIGHT;
    }

    // Key up
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_UP) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_UP)) && currentDirection != Direction::DOWN) {
        nextDirection = Direction::UP;
    }

    // Key down
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_DOWN) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_DOWN)) && currentDirection != Direction::UP) {
        nextDirection = Direction::DOWN;
    }

}


bool GameManager::isOutOfBounds(const Node &node) const {
    // Check if crash with borders
    int xPos = node.grid_x;
    int yPos = node.grid_y;
    return (xPos < 0 || yPos < 0 || xPos >= board_columns || yPos >= board_rows);
}


Vector2D GameManager::getVelocityVector(Direction direction) {
    switch (direction) {
        case Direction::LEFT:
            return Vector2D{-1, 0};
        case Direction::RIGHT:
            return Vector2D{1, 0};
        case Direction::UP:
            return Vector2D{0, -1};
        case Direction::DOWN:
            return Vector2D{0, 1};
    }

}

void GameManager::getValidPosition(Node &obj) {
    auto newPos = getRandomNode();
    while (!isEmptyNode(newPos) || isTooCloseToSnake(newPos) || newPos == obj) {
        newPos = getRandomNode();
    }
    obj = newPos;
}

Node GameManager::getRandomNode() {
    auto x = rand() % (board_columns - 1);
    auto y = rand() % (board_rows - 1);
    return Node{x, y};
}

bool GameManager::isEmptyNode(const Node &node) const {

    return !isObstacle(node) &&
           !isSnake(node) &&
           !isApple(node);
}

Node GameManager::getSnakeHeadNextPos(Node &head, Vector2D &vel) {
    return head + vel;
}

bool GameManager::isSnake(const Node &node) const {
    auto body = snake_new->getBody();
    return find(body.begin(), body.end(), node) != body.end();
}

bool GameManager::isApple(const Node &nextPos) const {
    return nextPos == appleNode;
}

bool GameManager::isObstacle(const Node &node) const {
    if (obstaclesVector.size() == 0)
        return false;

    return find(obstaclesVector.begin(), obstaclesVector.end(), node) != obstaclesVector.end();
}

// check if the node is directly ahead of the snake
bool GameManager::isTooCloseToSnake(const Node &node) const {
    auto radius = sqrt(
            pow(node.grid_x - snake_new->getHead().grid_x, 2) +
            pow(node.grid_y - snake_new->getHead().grid_y, 2));
    return radius <= Specs.MINIMUM_SPAWN_RADIUS;
}

void GameManager::playAppleSound() {
    appleSound->playSoundEffect();
}

bool GameManager::snakeCrashesWith(Node &node) {
    return (isSnake(node) && node != snake_new->getTail()) ||
           isObstacle(node);

}

void GameManager::increaseSpeed(float &currentInterval) {
    if (currentInterval < min_move_interval) {
        //guard for excessive speeds;
        currentInterval = min_move_interval;
    } else {
        float speedUpdateStep = (move_update_rate - min_move_interval) / (board_rows * board_columns);
        currentInterval -= speedUpdateStep;
    }
}

/*
 * @file: GameManager.cpp
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#include "GameManager.h"
#include "RendererManager.h"
#include <iostream>
#include <algorithm>
#include <renderers/AppleRenderer.h>
#include <renderers/ObjectListRenderer.h>
#include <renderers/BackgroundRenderer.h>
#include <AssetPaths.h>

using namespace std;

/* Initializes SDL, creates the game window and fires off the timer. */
GameManager::GameManager() {
	SDLManager::Instance().init();
	m_window = SDLManager::Instance().createWindow("SnakePlusPlus by Hartmann, Alvern, and Marescaux");
	Timer::Instance().init();
}


void GameManager::loadAssets() {
	// Load sounds
	gameMusic = std::make_unique<SDLMusic>(audio.level);
	appleSound = std::make_shared<SDLSound>(audio.crunch);
	gruntSound = std::make_shared<SDLSound>(audio.grunt);
	bonusSound = std::make_shared<SDLSound>(audio.wormhole);
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
    snake_new = std::make_shared<Snake>(startBody);
    getValidPosition(appleNode );

	gameMusic->playMusic();
}

void GameManager::InitRendererManager() {
	auto bg = make_shared<SDLPng>(images.background);
	auto bgRenderer = BackgroundRenderer{bg};
	auto appleRenderer = make_shared<AppleRenderer>(images.apple, appleNode);
	auto snakeRenderer = make_shared<SnakeRenderer>(
			images.snakeHead, images.snakeBody, images.snakeTail,
			*snake_new, direction
	);
	auto obstacle = make_shared<SDLPng>(images.obstacle);
	auto teleporter =make_shared<SDLPng>(images.wormhole);
	auto obstacleRenderer = make_shared<ObjectListRenderer>(obstacle, obstaclesVector);
    auto teleporterRenderer = make_shared<ObjectListRenderer>(teleporter, teleporterVector);
	auto objectRenderers = vector<shared_ptr<Renderer>>{appleRenderer, obstacleRenderer, teleporterRenderer, snakeRenderer};

	rendererManager = RendererManager{bgRenderer, objectRenderers};
}

/* Kicks off/is the the gameloop */
void GameManager::play() {
	//auto renderer = SDLManager::Instance().getRenderer(*(SDLManager::Instance().getMainWindow()));

	loadAssets();
	init();
	InitRendererManager();

	srand((unsigned int) time(nullptr));

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
        if (teleportersInstantiated && !teleporterInUse) teleporter_spawn_time += m_time_delta;
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

			//render graphics to screen
			rendererManager.renderAll();

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

    if (!teleporterInUse && isTeleporter(snakeHead)){
        if (snakeHead.hasSamePosition(teleporterVector.at(0))){
            nextPos = teleporterVector.at(1);
        } else {
            nextPos = teleporterVector.at(0);
        }
        bonusSound->playSoundEffect();
        teleporterInUse = true;
    } else if (isTeleporter(snake_new->getTail()) && teleporterInUse){
        teleporterInUse = false;
    }


    if (isOutOfBounds(nextPos) || snakeCrashesWith(nextPos)) {
        cout << "Game over!" << endl;
        gruntSound->playSoundEffect();
        running = false;
        return;
    }


    if (isApple(nextPos)) {
        snake_new->grow(nextPos);
        respawnApple();

        increaseSpeed(move_update_rate);
        appleSound->playSoundEffect();
        score++;
        scoreDelta++;
        cout << "Score: " << score << endl;
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

    if (teleportersInstantiated && !teleporterInUse && teleporter_spawn_time >= teleporter_spawn_time_delta){
        respawnTeleporter();
    }


    if (score == Specs.TELEPORTER_INSTANTIATE_SCORE && !teleportersInstantiated){
        instantiateTeleporters();
        teleportersInstantiated = true;
    }

    //create a new obstacle
    if (scoreDelta >= Specs.OBSTACLE_SPAWN_RATE) {
        Node newObstacle;
        getValidPosition(newObstacle);
        obstaclesVector.push_back(newObstacle);
        cout << "New obstacle on the board!"<< endl;

		scoreDelta = 0;
    }

}

void GameManager::respawnApple() {
    getValidPosition(appleNode);
    apple_spawn_time_delta = Specs.MIN_APPLE_RESPAWN_TIME + rand() % Specs.APPLESPAWN_TIME_DELTA;
    apple_spawn_time = 0;
}

void GameManager::respawnTeleporter(){
    if (rand() % 2 == 1){
        getValidPosition(teleporterVector.at(0));
    } else {
        getValidPosition(teleporterVector.at(1));
    }
    teleporter_spawn_time_delta = Specs.MIN_TELEPORTER_RESPAWN_TIME + rand() % Specs.TELEPORTER_TIME_DELTA;
    teleporter_spawn_time = 0;
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
		default:
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
	       !isTeleporter(node) &&
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

bool GameManager::isTeleporter(const Node &node) const {
    if (teleporterVector.size() == 0) return false;
    if (node == teleporterVector.at(0)) return true;
    else return node == teleporterVector.at(1);
}

void GameManager::instantiateTeleporters() {
    Node teleporter1;
    Node teleporter2;
    getValidPosition(teleporter1);
    getValidPosition(teleporter2);
    teleporterVector.push_back(teleporter1);
    teleporterVector.push_back(teleporter2);
    cout << "Wormholes now on the board!" << endl;
}

// check if the node is directly ahead of the snake
bool GameManager::isTooCloseToSnake(const Node &node) const {
	auto radius = sqrt(
			pow(node.grid_x - snake_new->getHead().grid_x, 2) +
			pow(node.grid_y - snake_new->getHead().grid_y, 2));
	return radius <= Specs.MINIMUM_SPAWN_RADIUS;
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
        float speedUpdateStep = (min_move_interval - currentInterval) / Specs.MAX_SPEED_CONSTANT;
        currentInterval += speedUpdateStep;
    }
}

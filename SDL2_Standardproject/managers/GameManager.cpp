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
	m_window = SDLManager::Instance().createWindow("SnakePlusPlus by Hartmann, Alvern, and Marescaux");
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

	gameboard = std::make_shared<GameBoard>(board_columns, board_rows);

	// get 4 joint nodes from the board
	Node head = gameboard->getNode(15, 12);
	Node body1 = gameboard->getNode(15, 11);
	Node body2 = gameboard->getNode(15, 10);
	Node body3 = gameboard->getNode(15, 9);
	Node body4 = gameboard->getNode(15, 8);

	list <Node> startBody{head, body1, body2, body3, body4};

	velocityVec = getVelocityVector(Direction::DOWN);
	snake_new = std::make_shared<Snake_new>(startBody);
	appleNode = Node{29, 19};

	gameMusic->playMusic();
}


/* Kicks off/is the the gameloop */
void GameManager::play() {
	//auto renderer = SDLManager::Instance().getRenderer(*(SDLManager::Instance().getMainWindow()));

	loadAssets();
	init();
	auto snakeRenderer = SnakeRenderer{*playerHeadImage, *playerBodyImage, *playerTailImage, *snake_new, direction};
	auto appleRenderer = AppleRenderer{appleImage, appleNode};
	auto obstacleRenderer = ObstacleRenderer{obstacleImage, obstaclesVector};
	auto renderers = vector<Renderer*>{&snakeRenderer, &appleRenderer, &obstacleRenderer};

	srand((unsigned int) time(nullptr));

	// Calculate render frames per second (second / frames) (60)
	float render_fps = 1.f / 60.f;
	m_lastRender = render_fps; // set it to render immediately

	float move_update = 10.f / 60.f;
	m_lastMove = move_update;

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
		} else
			// Input Management
			updateDirection(direction, nextDirection);


		Timer::Instance().update();

		//the logic frames
		m_lastMove += Timer::Instance().deltaTime();
		if (m_lastMove >= move_update) {
			direction = nextDirection;
			updateBoard();
			m_lastMove = 0.f;
		}


		//Render
		// Update time since last render
		m_lastRender += Timer::Instance().deltaTime();

		// Check if it's time to render
		if (m_lastRender >= render_fps) {
			// Add bitmaps to renderer
			background->draw();

			for (auto &&renderer : renderers) {
				renderer->render();
			}

			// Render window
			SDLManager::Instance().renderWindow(m_window);
			m_lastRender = 0.f;
		}

		// Sleep to prevent CPU exhaustion (1ms == 1000 frames per second)
		SDL_Delay(1);
	}

}

void GameManager::updateBoard() {
	velocityVec = getVelocityVector(direction);
	auto snakeHead = snake_new->getHead();
	Node nextPos = getSnakeHeadNextPos(snakeHead, velocityVec);

	if (isOutOfBounds(nextPos) || isObstacle(nextPos) || isSnake(nextPos)) {
		gruntSound->playSoundEffect();
		running = false;
		return;
	}

	if (isApple(nextPos)) {
		snake_new->grow(nextPos);
		getValidPosition(appleNode);
		appleSound->playSoundEffect();
		score++;
		scoreDelta++;

	} else {
		snake_new->move(nextPos);
	}

	if (snake_new->getLength() >= (board_columns * board_rows - obstaclesVector.size())) {
		running = false;
		return;
	}

	//create a new obstacle
	if (scoreDelta >= 1) {
		Node newObstacle;
		getValidPosition(newObstacle);
		obstaclesVector.push_back(newObstacle);

		//increase speed between game updates
		m_lastMove *= 4.f / 5.f;

		scoreDelta = 0;
	}

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


void GameManager::drawGrid(int x, int y, SDL_Renderer &renderer) {
	for (int i = 0; i != x; i++) {
		for (int j = 0; j != y; j++) {
			auto xPos = node_diameter * i;
			auto yPos = node_diameter * j;
			SDL_Rect node = {xPos, yPos, node_diameter, node_diameter};
			SDL_RenderDrawRect(&renderer, &node);
		}
	}
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

	return Direction::DOWN; // to avoid compilation warnings and as a safety net
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
	return gameboard->getNode(x, y);

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

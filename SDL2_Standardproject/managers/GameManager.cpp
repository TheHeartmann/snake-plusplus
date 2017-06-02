/*
 * @file: GameManager.cpp
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#include "GameManager.h"
#include <iostream>

using namespace std;

/* Initializes SDL, creates the game window and fires off the timer. */
GameManager::GameManager() {
    SDLManager::Instance().init();
    m_window = SDLManager::Instance().createWindow("My Awesome SDL 2.0 Game");
    Timer::Instance().init();
}

void GameManager::init() {
    // Load bitmaps


}

void GameManager::loadAssets() {
    background =  std::make_unique<SDLBmp>("SDL2_Standardproject/Assets/gfx/sdl2.bmp");
    playerHeadImage = std::make_shared<SDLBmp>("SDL2_Standardproject/Assets/gfx/SnakeHead_v1.bmp");
    playerBodyImage = std::make_shared<SDLBmp>("SDL2_Standardproject/Assets/gfx/SnakeBody_v1.bmp");
    appleImage = std::make_shared<SDLBmp>("SDL2_Standardproject/Assets/gfx/Apple_v1.bmp");
}


/* Kicks off/is the the gameloop */
void GameManager::play() {
	auto renderer = SDLManager::Instance().getRenderer(*(SDLManager::Instance().getMainWindow()));

    /*int startingLength = 3;
    float speed = 150.0f;
    int speedIncreaseRate = 10;*/
    loadAssets();

    Direction direction = Specs.SNAKE_HEAD_STARTDIR;
    int score = 0;

    srand(time(nullptr));


    Point2D playerStartingPosition((board_width / 2 - node_radius),
                                   (board_height / 2 - node_radius));
    Point2D applePosition = getRandomPoint();

    GameObject playerHead(playerStartingPosition, playerHeadImage, Direction::UP);
    GameObject playerBody(playerStartingPosition, playerBodyImage, Direction::UP);
    GameObject apple(applePosition, appleImage, Direction::UP);

    Snake snake(&playerHead, &playerBody, Specs.SNAKE_INITIAL_LENGTH);



    // Calculate render frames per second (second / frames) (60)
    float render_fps = 1.f / 60.f;
    m_lastRender = render_fps; // set it to render immediately

    // Gameloop
    while (running) {

        //Input
        // Update input and deltatime
        InputManager::Instance().Update();

        // Exit on [Esc], or window close (user X-ed out the window)
        if (InputManager::Instance().hasExit() || InputManager::Instance().KeyDown(SDL_SCANCODE_ESCAPE))
            break;
        else
            // Input Management
            updateDirection(direction);


        Timer::Instance().update();

        // Calculate displacement based on deltatime
        auto displacement = speed * Timer::Instance().deltaTime();

        //Logic

        snake.updatePosition(direction, displacement);

        //Check if we died
        GameObject head(*(snake.getHead()));
        running = !isOutOfBounds(head);
        //		AutoCannibalismCheck (&snake);

        //Check if we found object
        if (CrashedWithObjectCheck(&head, &apple)) {
            score++;
            speed += acceleration;
            cout << "Score: " << score << endl;
            //Grow body size
            snake.increaseLength();
            /*apple.setPosition(getRandomPoint(&apple, board_width, board_height));*/
            apple.setPosition(getRandomPoint());
        }

        //push earlier turn to turn queue
        if (m_lastRender >= render_fps) {
            snake.pushPreviousTurnPosition(snake.getHead()->getPosition());
        }

        //Render
        // Update time since last render
        m_lastRender += Timer::Instance().deltaTime();

        // Check if it's time to render
        if (m_lastRender >= render_fps) {
            // Add bitmaps to renderer
            background->draw();
            snake.drawSnake();
            apple.getImage()->draw();
            // Render window
            drawGrid()
            SDLManager::Instance().renderWindow(m_window);
            m_lastRender = 0.f;
        }

        // Sleep to prevent CPU exthaustion (1ms == 1000 frames per second)
        SDL_Delay(1);
    }

}

//Checks input and sets direction
void GameManager::updateDirection(Direction &direction) {

    // Left key
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_LEFT) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_LEFT)) && direction != Direction::RIGHT) {
        direction = Direction::LEFT;
    }

    // Right key
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_RIGHT) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_RIGHT)) && direction != Direction::LEFT) {
        direction = Direction::RIGHT;
    }

    // Key up
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_UP) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_UP)) && direction != Direction::DOWN) {
        direction = Direction::UP;
    }

    // Key down
    if ((InputManager::Instance().KeyDown(SDL_SCANCODE_DOWN) ||
         InputManager::Instance().KeyStillDown(SDL_SCANCODE_DOWN)) && direction != Direction::UP) {
        direction = Direction::DOWN;
    }

}

//Checks if player crashes with window borders
bool GameManager::isOutOfBounds(GameObject &player) {
    // Check if crash with borders

    float x = player.getPosition().getX();
    float y = player.getPosition().getY();
    return (x < 0 || y < 0 || x >= board_width - node_diameter || y >= board_height - node_diameter);
}

//Checks is player crashes with self
void GameManager::AutoCannibalismCheck(Snake *player) {
    //Add check for autocannibalism when snake has more body parts
    //head can crash with closest 2 or 3 body parts without ending game to minimize unintended crashes?

    for (auto i = 1; i <= player->getLength() - 3; i++) {
        if (CrashedWithObjectCheck(player->getHead(), player->getBodyPartAt(i)))
            running = false;
    }

}

//Checks if player crashes with object
bool GameManager::CrashedWithObjectCheck(GameObject *player, GameObject *object) {
    //Make 4 points from corners of object
    //Make square from player head represented as if statement
    //Check if points are inside square

    // Checks the upper left corner of object
    if (player->getPosition().isInsideSquare(object->getPosition().getX(),
                                             object->getPosition().getY(),
                                             object->getImage()->getWidth(),
                                             object->getImage()->getHeight()))
        return true;

    // Checks the upper right corner of object
    if (Point2D(player->getPosition().getX() + player->getImage()->getWidth(),
                player->getPosition().getY()
    ).isInsideSquare(object->getPosition().getX(),
                     object->getPosition().getY(),
                     object->getImage()->getWidth(),
                     object->getImage()->getHeight()))
        return true;

    // Checks the lower left corner of object
    if (Point2D(player->getPosition().getX(),
                player->getPosition().getY() + player->getImage()->getHeight()
    ).isInsideSquare(object->getPosition().getX(),
                     object->getPosition().getY(),
                     object->getImage()->getWidth(),
                     object->getImage()->getHeight()))
        return true;

    // Checks the lower right corner of object
    if (Point2D(player->getPosition().getX() + player->getImage()->getWidth(),
                player->getPosition().getY() + player->getImage()->getHeight()
    ).isInsideSquare(object->getPosition().getX(),
                     object->getPosition().getY(),
                     object->getImage()->getWidth(),
                     object->getImage()->getHeight()))
        return true;

    return false;
}

//Sets image position to random position between 0 and board width/height
/*
Point2D GameManager::getRandomPoint(GameObject *image, int boardWidth, int boardHeight) {
    return Point2D(static_cast<float>(rand() % (boardWidth - image->getImage()->getWidth())),
                   static_cast<float>(rand() % (boardHeight - image->getImage()->getHeight())));
}
*/
Point2D GameManager::getRandomPoint() {
    return Point2D(
            static_cast<float>(rand() % (board_width - node_diameter)),
            static_cast<float>(rand() % (board_height - node_diameter))
    );
}


void GameManager::drawGrid(Node **grid, int x, int y, SDL_Renderer &renderer) {
	auto diameter = Specs.NODE_DIAMETER;
	for (int i = 0; i != x; i++) {
		grid[i] = new Node[y];
		for (int j = 0; j != y; j++) {
			auto xPos = diameter*x;
			auto yPos = diameter*y;
			SDL_Rect node = {xPos, yPos, diameter, diameter};
			SDL_RenderDrawRect(&renderer, &node);
		}
	}
}


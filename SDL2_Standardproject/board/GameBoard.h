//
// Created by clement on 01/06/17.
//

#ifndef SNAKE_PLUSPLUS_GAMEBOARD_H
#define SNAKE_PLUSPLUS_GAMEBOARD_H

#include <memory>
#include <vector>
#include "Node.h"

using namespace std;

class GameBoard {
public:
    GameBoard() : GameBoard{5, 15} {}

    GameBoard(int columns, int rows);

    Node **getBoard();

    shared_ptr<Node> getNode(int column, int row);


    ~GameBoard();

private:
    int columns;
    int rows;
    Node **board;

};

#endif //SNAKE_PLUSPLUS_GAMEBOARD_H

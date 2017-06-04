//
// Created by clement on 01/06/17.
//

#ifndef SNAKE_PLUSPLUS_GAMEBOARD_H
#define SNAKE_PLUSPLUS_GAMEBOARD_H

#include <memory>
#include <vector>
#include <Specifications.h>
#include "Node.h"

using namespace std;

class GameBoard {
public:
    GameBoard() : GameBoard{5, 15} {}

    GameBoard(int columns, int rows);

    Node getNode(int column, int row);


    ~GameBoard();

private:
    const int columns = Specs.BOARD_COLUMNS;
    const int rows = Specs.BOARD_ROWS;
    Node board[BOARD_COLS_MAC][BOARD_ROWS_MAC];

};

#endif //SNAKE_PLUSPLUS_GAMEBOARD_H

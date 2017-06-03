//
// Created by clement on 01/06/17.
//

#include "GameBoard.h"

GameBoard::GameBoard(int c, int r) : columns{c}, rows{r} {
    for (int i = 0; i != c; i++) {
        for (int j = 0; j != r; j++) {
            board[i][j] = Node(i, j);
        }
    }
}

GameBoard::~GameBoard() {
}

Node GameBoard::getNode(int column, int row) {
    return board[column][row];
}


//
// Created by clement on 01/06/17.
//

#include "GameBoard.h"

GameBoard::GameBoard(int c, int r) : columns{c}, rows{r} {
    board = new Node *[c];
    for (int i = 0; i != c; i++) {
        board[i] = new Node[r];
        for (int j = 0; j != r; j++) {
            Node n{i, j};
            board[i][j] = n;
        }
    }
}


Node **GameBoard::getBoard() {
    return board;
}

GameBoard::~GameBoard() {
    for (int i = 0; i != columns; i++)
        delete[] board[i];
    delete[] board;
}


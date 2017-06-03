//
// Created by clement on 01/06/17.
//

#include "GameBoard.h"

GameBoard::GameBoard(int c, int r) : columns{c}, rows{r} {
//    board = new shared_ptr<Node>*;
    for (int i = 0; i != c; i++) {
//        board[i] = new shared_ptr<Node>[r];
        for (int j = 0; j != r; j++) {
//	        shared_ptr<Node> nodePointer = make_shared(i, j);
//            Node n{i, j};
            board[i][j] = make_shared<Node>(i, j);
        }
    }
}

GameBoard::~GameBoard() {
//    for (int i = 0; i != columns; i++)
//        delete[] board[i];
//    delete[] board;
}

//Node GameBoard::getNode(int column, int row) {
shared_ptr<Node> GameBoard::getNode(int column, int row) {
    //Node node = board[column][row];
    return board[column][row];
}


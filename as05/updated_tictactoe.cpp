/*
  FA24 CS-11 Assignment 5 - TicTacToe (w/o GUI)
  Source(s): N/A
*/

// Starter code for Assignment #5, tictactoe.cpp
#include <iostream>

using namespace std;

// Array that maps player numbers to their respective symbols.
const char SIGIL[3]={'.', 'X', 'O'};

// Function Prototypes.
void drawBoard(int board[3][3]);
bool isMoveLegal(int board[3][3], int row, int column);
int winner(int board[3][3]);
bool isGameOver(int board[3][3]);


/**
    This function is currently hardcoded to always print an empty board.
    TODO: Update this function so it properly prints out each element in
          the 2D array.
    Draw the board using the SIGIL array:
        "." for empty squares,
        'X' for player 1,
        'O' for player 2.

    @param board - a 2D integer array that represents the players on the
                   board.
*/
void drawBoard(int board[3][3]) {
//index i & j elemtent to traslant it the the sigil array
//SIGIL[BOARD[2][1]] -> SIGIL[2] -> X
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << SIGIL[board[i][j]];
        }
    cout << endl;
    }
}

/**
    This function, which should check if a move is legal on the board, is
    currently hardcoded to always return true.
    TODO: Update this function so it return false if row or column are out
          of bounds, or if that spot on the board is already taken.
          Otherwise return true.

    @param board - a 2D integer array that represents the players on the
                   board.
    @param row - the row index of the requested move.
    @param column - the column index of the requested move.

    @return whether or not the move is legal.
*/
bool isMoveLegal(int board[3][3], int row, int column) {

    if(row < 0 || row >= 3 || column < 0 || column >= 3) {
        return false;
    }else if (SIGIL[board[row][column]] == 'X' ||
              SIGIL[board[row][column]] == 'O') {
        return false;
    }else{
        return true;
    }
}

/**
   This function should determine the winner of the game; it's currently
   hardcoded to always return 0 (no winner).
   TODO: Update this function to return the winner, else return 0.

   @param board - a 2D integer array that represents the players on the
                  board.
   @return 1 if player 1 'X' has won, or 2 if player 2 'O' has won, or 0
             if neither player has won.
*/
int winner(int board[3][3]) {
    // Rows & Column Check

    for(int i = 0; i < 3; i++) {
        // Column
        if((SIGIL[board[0][i]] == 'X') && (SIGIL[board[1][i]] == 'X')
           && (SIGIL[board[2][i]] == 'X')) {
            return 1;
        }else if((SIGIL[board[0][i]] == 'O') && (SIGIL[board[1][i]] == 'O')
                 && (SIGIL[board[2][i]] == 'O')) {
            return 2;
        }
        // Row
        if((SIGIL[board[i][0]] == 'X') && (SIGIL[board[i][1]] == 'X')
                 && (SIGIL[board[i][2]] == 'X')) {
            return 1;
        }else if((SIGIL[board[i][0]] == 'O') && (SIGIL[board[i][1]] == 'O')
                 && (SIGIL[board[i][2]] == 'O')) {
            return 2;
        }
    }
    // Diagonal Check
    if((SIGIL[board[0][0]] == 'X') && (SIGIL[board[1][1]] == 'X')
               && (SIGIL[board[2][2]] == 'X')) {
        return 1;
    }else if((SIGIL[board[0][0]] == 'O') && (SIGIL[board[1][1]] == 'O')
               && (SIGIL[board[2][2]] == 'O')) {
        return 2;
    }

    if((SIGIL[board[0][2]] == 'X') && (SIGIL[board[1][1]] == 'X')
               && (SIGIL[board[2][0]] == 'X')) {
        return 1;
    }else if((SIGIL[board[0][2]] == 'O') && (SIGIL[board[1][1]] == 'O')
               && (SIGIL[board[0][2]] == 'O')) {
        return 2;
    }

    // Tie Game
    return 0;
}

/**
     This function checks if the game is over.
     @param board - a 2D integer array that represents the players on the
                    board.
     @return true if any player has three in a row or if the board is full.
             false if there's still space on the board.
*/
bool isGameOver(int board[3][3]) {
    if (winner(board) == 1 || winner(board) == 2)
        return true;

    for (int r = 0; r <= 2; r++)
        for (int c = 0; c <= 2; c++)
            if (board[r][c] == 0)
                return false;

    return true;
}


int main() {
    // Initialize board to all 0.
    // It will later be filled in with 1 or 2 for taken squares.
    int board[3][3]={{0}};
    int player = 1;
    int row, column, result;
    bool legalMove;

    // Start game.
    drawBoard(board);
    while (!isGameOver(board)) {
        cout << "Player " << player << "(" << SIGIL[player]
             << "), your move?";
        cin >> row >> column;

        legalMove = isMoveLegal(board, row, column);
        while (!legalMove) {
            cout << "Player " << player << "(" << SIGIL[player]
                 << "), your move?";
            cin >> row >> column;
            legalMove = isMoveLegal(board, row, column);
        }
        board[row][column] = player;
        drawBoard(board);
        player = 3 - player;
    }

    // Game over.
    result = winner(board);
    if (result == 0) {
        cout << "Tie Game" << endl;
    } else {
        cout << "Player " << result << "(" << SIGIL[result]
             << ") wins!" << endl;
    }

    return 0;
}


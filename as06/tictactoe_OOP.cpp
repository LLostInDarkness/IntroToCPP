/*
  FA24 CS-11 Assignment 06: Tic Tac Toe OOP
  Sources / Works Cited: Referenced GuessingGame_OOP.cpp
  & tictactoe.cpp (as05)

*/

#include <iostream>

//Considered as a bad programming standard
//using namespace std;

class TicTacToe {
    public:
        TicTacToe();
        void play();

    private:
        // Hint: Initialize these attributes in the constructor.
        char sigil[3];
        int board[3][3];

        void drawBoard();
        bool isMoveLegal(int row, int column);
        int winner();
        bool isGameOver();
};

TicTacToe::TicTacToe() {  // Constructs the game
    std::cout << "Constructing game board..." << std::endl;
    sigil[0] = '.';
    sigil[1] = 'X';
    sigil[2] = 'O';

    // Use for loop in as05 updated cpp
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            board[i][j] = 0;
        }
    }
}

void TicTacToe::play() {  // Will use all private variables
    std::cout << "Starting game..." << std:: endl;

    int player = 1;
    int row, column, result;
    bool legalMove;

    drawBoard();
    //Copy and paste the while loop in as05 main (remove the params)
    while (!isGameOver()) {
        std::cout << "Player " << player << "(" << sigil[player]
             << "), your move?";
        std::cin >> row >> column;

        legalMove = isMoveLegal(row, column);
        while (!legalMove) {
            std::cout << "Player " << player << "(" << sigil[player]
                 << "), your move?";
            std::cin >> row >> column;
            legalMove = isMoveLegal(row, column);
        }
        board[row][column] = player;
        drawBoard();
        player = 3 - player;
    }

    // Game over.
    result = winner();
    if (result == 0) {
        std::cout << "Tie Game" << std::endl;
    } else {
        std::cout << "Player " << result << "(" << sigil[result]
             << ") wins!" << std::endl;
    }

}

void TicTacToe::drawBoard() {
    std::cout << "  0 1 2" << std::endl;

    for(int i = 0; i < 3; i++) {
        //std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << sigil[board[i][j]] << " ";
        }
    std::cout << std::endl;

    }

}

bool TicTacToe::isMoveLegal(int row, int column) {
    if(row < 0 || row >= 3 || column < 0 || column >= 3) {
        return false;
    }else if (sigil[board[row][column]] == 'X' ||
              sigil[board[row][column]] == 'O') {
        return false;
    }else{
        return true;
    }
}

int TicTacToe::winner() {
    // Rows & Column Check

    for(int i = 0; i < 3; i++) {
        // Column
        if((sigil[board[0][i]] == 'X') && (sigil[board[1][i]] == 'X')
           && (sigil[board[2][i]] == 'X')) {
            return 1;
        }else if((sigil[board[0][i]] == 'O') && (sigil[board[1][i]] == 'O')                  && (sigil[board[2][i]] == 'O')) {
            return 2;
        }
        // Row
        if((sigil[board[i][0]] == 'X') && (sigil[board[i][1]] == 'X')
                 && (sigil[board[i][2]] == 'X')) {
            return 1;
        }else if((sigil[board[i][0]] == 'O') && (sigil[board[i][1]] == 'O')                  && (sigil[board[i][2]] == 'O')) {
            return 2;
        }
    }
    // Diagonal Check
    if((sigil[board[0][0]] == 'X') && (sigil[board[1][1]] == 'X')
               && (sigil[board[2][2]] == 'X')) {
        return 1;
    }else if((sigil[board[0][0]] == 'O') && (sigil[board[1][1]] == 'O')
               && (sigil[board[2][2]] == 'O')) {
        return 2;
    }

    if((sigil[board[0][2]] == 'X') && (sigil[board[1][1]] == 'X')
               && (sigil[board[2][0]] == 'X')) {
        return 1;
    }else if((sigil[board[0][2]] == 'O') && (sigil[board[1][1]] == 'O')
               && (sigil[board[0][2]] == 'O')) {
        return 2;
    }

    // Tie Game
    return 0;

}

bool TicTacToe::isGameOver() {
    if (winner() == 1 || winner() == 2)
        return true;

    for (int r = 0; r <= 2; r++)
        for (int c = 0; c <= 2; c++)
            if (board[r][c] == 0)
                return false;

    return true;
}


int main() {
    TicTacToe Game;  // Calls the default constructor
    Game.play();

    return 0;
}

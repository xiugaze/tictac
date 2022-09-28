#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct Move {
    int row, col;
};

char player = 'x', opponent = 'o';

bool movesLeft(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(board[i][j] == '_') {
                return true;
            }
        }
    }
    return false;
}

int evaluate(char board[3][3]) {
    // row
    for (int row = 0; row < 3; row++) {
        if(board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            if(board[row][0] == player) {
                return 1;
            } else if (board[row][0] == opponent) {
                return -1;
            }
        }
    }

    // column
    for (int col = 0; col < 3; col++) {
        if(board[0][col] == board[1][col] && board[0][col] == board[2][col]) {
            if(board[0][col] == player) {
                return 1;
            } else if (board[0][col] == opponent) {
                return -1;
            }
        }
    }

    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if(board[0][0] == player) {
                return 1;
            } else if (board[0][0] == opponent) {
                return -1;
            }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if(board[0][2] == player) {
                return 1;
            } else if (board[0][2] == opponent) {
                return -1;
            }
    }
    // no wins
    return 0;
}

int minimax(char board[3][3], int depth, bool isOpponent) {
    int score = evaluate(board);

    // maximizer or minimizer wins
    if(score == 1 || score == -1) {
        return score;
    }

    // tie
    if(movesLeft(board) == false) {
        return 0;
    }

    if(isOpponent) {
        int best = -1000;
        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                if (board[i][j]=='_') {
                    board[i][j] = player;
                    best = max(best, minimax(board, depth+1, !isOpponent) );
                    board[i][j] = '_';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                if (board[i][j]=='_') {
                    board[i][j] = opponent;
                    best = min(best, minimax(board, depth+1, !isOpponent));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}
    
Move findBestPlayer(char board[3][3]) {
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (board[i][j]=='_') {
                board[i][j] = player;
 
                int moveVal = minimax(board, 0, false);
 
                board[i][j] = '_';
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

Move findBestOpponent(char board[3][3]) {
    int bestVal = 1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (board[i][j]=='_') {
                board[i][j] = opponent;
 
                int moveVal = minimax(board, 0, true);
 
                board[i][j] = '_';
                if (moveVal < bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void printBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
}

// int main() {
//     char board[3][3] =
//     {
//         { '_', '_', '_' },
//         { '_', '_', '_' },
//         { '_', '_', '_' }
//     };

//     bool moves = true;
//     while(moves) {
//         printBoard(board);

//         Move bestMove = findBestPlayer(board);
//         printf("The best move for the player is ROW: %d COL: %d\n", bestMove.row, bestMove.col);
//         board[bestMove.row][bestMove.col] = player;

//         printBoard(board);

//         Move bestOpp = findBestOpponent(board);
//         printf("The best move for the opponent is ROW: %d COL: %d\n", bestOpp.row, bestOpp.col);
//         board[bestOpp.row][bestOpp.col] = opponent;

//         printf("\n\n");

//         moves = movesLeft(board);
//     }

//     // Move bestMove = findBestPlayer(board, player);

//     // printf("The best move for the opponent is ROW: %d COL: %d\n", bestOpp.row, bestOpp.col);

// }

int main() {
    char board[3][3] =
    {
        { '_', '_', '_' },
        { '_', '_', '_' },
        { '_', '_', '_' }
    };

    bool finished = false;
    while(!finished) {

        Move cur;
        printBoard(board);
        printf("Enter desired row");
        cin >> cur.row;
        printf("Enter desired column");
        cin >> cur.col;
        board[cur.row][cur.col] = player;

        printBoard(board);

        if(movesLeft) {
            Move bestOpp = findBestOpponent(board);
            printf("The best move for the opponent is ROW: %d COL: %d\n", bestOpp.row, bestOpp.col);
            board[bestOpp.row][bestOpp.col] = opponent;
        }

        printBoard(board);
        printf("\n\n");

        // finished = !movesLeft(board) || check(board);
        finished = !movesLeft(board) || evaluate(board) != 0;
    }
    string message = evaluate(board) == 1 ? "You win!" : "you'll never be enough";
    cout << message;

}
    
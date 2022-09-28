# tictac
This is a simple tic-tac-toe algorithm based around a von Neumann minmax principle. 

## Usage 
Running the .exe provides a simple command line interface for the game. Enter the 0-indexed row and column to play. 
The opponent will always calculate the best possible move. It is impossible for the player to win, only lose or draw. 

## Code
This program is a simple implementation of two-player minmax game theory. 
In minmax theory, there is a shared store of value represented by the game board. 
Player one is attempting to gain the largest amount of value, while player two is trying to minimize his own loss. 

In the tictac algorithm, the stored value is the game board itself, with a win for the player having the maximum value, while a win for the algorithm having the lowest value. 

For each iteration of the board, the algorithm recursively evaluates each possible move that can be performed from the current state. 
Next, the possible combinations that would produce a loss are pruned from the search pool. 
It then determines the lowest number of actions or "steps" required for a win, and follows the shortest path. 

This algorithm *does not* implement alpha-beta pruning, as the number of iterations for a board completion are at least 5 but no more than 9. Therefore, there's not enough performance loss to necessitate additional efficiency. 
In all honesty, I don't have a great hold of minmax alone, aside from any extra optimizations. However, on a 4x4 or 5x5 board, or for a different game like chess, it would be absolutely necessary to understand all possible optimizations. 

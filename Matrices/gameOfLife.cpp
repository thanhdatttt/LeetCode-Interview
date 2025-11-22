// The board is made up of an m x n grid of cells, where each cell has an initial state: 
// live (represented by a 1) or dead (represented by a 0). 
// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
// using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board.
// In this process, births and deaths occur simultaneously.

// Given the current state of the board, update the board to reflect its next state.


#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//  count alive cells arround current cell
int countAlive(vector<vector<int>>& board, int r, int c, vector<int> directions) {
    int n = board.size();
    int m = board[0].size();
    int count = 0;

    for (int dr : directions) {
        for (int dc : directions) {
            // direction is (0, 0) in the current cell so continue
            if (dr == 0 && dc == 0)
                continue;
            
            int nr = dr + r;
            int nc = dc + c;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                // get old state (0 or 1) then count
                count += board[nr][nc] & 1; 
            }
        }
    }

    return count;
}

void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<int> directions = {-1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // count live cells
            int lives = countAlive(board, i, j, directions);

            // current cell old state
            int cur = board[i][j] & 1;

            if (cur == 1) {
                // rule 2
                if (lives == 2 || lives == 3) {
                    board[i][j] |= 2; // live ( old state*2)
                }
            } else {
                // rule 4
                if (lives == 3) {
                    board[i][j] |= 2; // live ( old state*2)
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if old state is 0 -> shift right -> next will be 0
            // if old state is 1 -> have * 2 -> shift right -> next will be 1
            board[i][j] >>= 1;
        }
    }
}

int main() {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    printMatrix(board);
    cout << endl;

    gameOfLife(board);
    printMatrix(board);
    return 0;
}
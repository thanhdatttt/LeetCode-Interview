// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

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

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    bool isFirstRowZero = false;
    bool isFirstColZero = false;
    // check first row contains zero
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0){
            isFirstRowZero = true;
            break;
        }
    }

    // check first col contains zero
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            isFirstColZero = true;
            break;
        }
    }

    // use first row and col as marker to check which row and col is 0
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // set row and col to zero if match with marker (except first row and col)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero first row if needed
    if (isFirstRowZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero first column if needed
    if (isFirstColZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,1,1},{1,0,1},{1,1,1}
    };

    setZeroes(matrix);

    printMatrix(matrix);

    return 0;
}
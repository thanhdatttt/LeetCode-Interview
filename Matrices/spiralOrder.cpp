// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;

    // borders
    int left = 0;
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;

    // move spiral
    while (top <= bottom && left <= right) {
        // left -> right
        for (int j = left; j <= right; j++) {
            res.push_back(matrix[top][j]);
        }
        top++;

        // top -> bottom
        for (int j = top; j <= bottom; j++) {
            res.push_back(matrix[j][right]);
        }
        right--;

        // right -> left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // bottom -> top
        if (left <= right) {
            for (int j = bottom; j >= top; j--) {
                res.push_back(matrix[j][left]);
            }
            left++;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12}
    };

    vector<int> res = spiralOrder(matrix);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size())
        return s;
    
    // store each row
    vector<string> rows(numRows);
    int curRow = 0;
    int isGoDown = false;

    for (char c : s) {
        rows[curRow] += c;

        // reverse direction when reaching top or bottom
        if (curRow == 0 || curRow == numRows - 1)
            isGoDown = !isGoDown;

        curRow += isGoDown ? 1 : -1;
    }

    // get result
    string res = "";
    for (string row : rows) {
        res += row;
    }
    return res;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 4;

    cout << convert(s, numRows) << endl;
    return 0;
}
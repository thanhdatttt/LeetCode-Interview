// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Roman numerals are usually written largest to smallest from left to right. 
// However, the numeral for four is not IIII. Instead, the number four is written as IV. 
// Because the one is before the five we subtract it making four. 
// The same principle applies to the number nine, which is written as IX

// Given a roman numeral, convert it to an integer.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> converter = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

int romanToInt(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        int value = converter[s[i]];

        if (i + 1 < s.length() && converter[s[i + 1]] > value) {
            result -= value;
        } else {
            result += value;
        }
    }

    return result;
}

int main() {
    string s = "XIV";
    cout << romanToInt(s) << endl;
    
    return 0;
}
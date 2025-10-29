// integer to roman

#include <iostream>
#include <vector>
using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> converter = {
        {1000, "M"},
        {900,  "CM"}, 
        {500,  "D"},  
        {400,  "CD"}, 
        {100,  "C"},  
        {90,   "XC"}, 
        {50,   "L"},  
        {40,   "XL"}, 
        {10,   "X"},  
        {9,    "IX"},
        {5,    "V"}, 
        {4,    "IV"},
        {1,    "I"}, 
    };

    string result = "";

    for (auto [key, symbol]: converter) {
        while (num >= key) {
            result += symbol;
            num -= key;
        }
    }

    return result;
}

int main() {
    int num = 3749;

    cout << intToRoman(num) << endl;

    return 0;
}
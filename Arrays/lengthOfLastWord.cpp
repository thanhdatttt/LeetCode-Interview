// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.
#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    // int n = s.length();
    // int i = n - 1;
    // int length = 0;
    // while (i >= 0 && s[i] == ' ') {
    //     i--;
    // }

    // while (i >= 0 && s[i] != ' ') {
    //     length++;
    //     i--;
    // }

    // return length;

    // second solution
    int end = s.find_last_not_of(' ');
    if (end == string::npos) return 0; // string is all spaces

    int start = s.find_last_of(' ', end);
    return end - start;
}

int main() {
    string s = "   fly me   to   the moon  ";
    
    cout << lengthOfLastWord(s) << endl;

    return 0;
}
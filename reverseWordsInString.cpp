// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. 
// The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    // first solution
    int n = s.length();
    if (n <= 1) {
        return s;
    }

    // reverse all string
    reverse(s.begin(), s.end());

    // reverse again words in string
    int k = 0;
    for (int i = 0; i < n; i++) {
        // find start of word
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i >= n)
            break;
        
        // find end of word
        int j = i;
        while (j < n && s[j] != ' ') {
            j++;
        }
        // reverse word
        reverse(s.begin() + i, s.begin() + j);

        // remove extra space
        if (k > 0) {
            s[k++] = ' ';
        }
        for (int t= i; t < j; t++ ) {
            s[k++] = s[t];
        }
        i = j;
    }
    s.resize(k);

    return s;

    // second solution
    // stringstream ss(s);
    // vector<string> words;
    // string word;

    // while (ss >> word) {   // automatically skips extra spaces
    //     words.push_back(word);
    // }

    // reverse(words.begin(), words.end());

    // string result;
    // for (int i = 0; i < words.size(); i++) {
    //     result += words[i];
    //     if (i < words.size() - 1) result += " ";
    // }
    // return result;
}

int main() {
    string s = "  hello world  ";

    cout << reverseWords(s) << endl;
    cout << s.length() << endl;
    return 0;
}
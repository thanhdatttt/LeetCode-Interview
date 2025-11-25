// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. 
// Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

bool wordPattern(string pattern, string s) {
    // split s into words
    vector<string> words;
    string temp;
    stringstream ss(s);

    while (ss >> temp) {
        words.push_back(temp);
    }

    if (words.size() != pattern.size()) {
        return false;
    }

    // hashmap for store
    unordered_map<char, string> mp1;
    unordered_map<string, char> mp2;

    for (int i = 0; i < pattern.size(); i++) {
        // check condition
        if (mp1.count(pattern[i]) && mp1[pattern[i]] != words[i]) {
            return false;
        }
        if (mp2.count(words[i]) && mp2[words[i]] != pattern[i]) {
            return false;
        }

        // save to hashmap
        mp1[pattern[i]] = words[i];
        mp2[words[i]] = pattern[i];
    }

    return true;
}

int main() {
    string pattern = "abba", s = "dog cat cat dog";

    cout << wordPattern(pattern, s) << endl;
    
    return 0;
}
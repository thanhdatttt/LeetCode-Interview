// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    // first solution use hashmap with unordered map
    // unordered_map<char, int> mp;

    // for (char c : magazine) {
    //     mp[c]++;
    // }

    // for (char c : ransomNote) {
    //     if (!mp.count(c) || mp[c] == 0) {
    //         return false;
    //     }
    //     mp[c]--;
    // }

    // return true;

    // second solution use normal array to store the number of letters
    int count[26] = {0};

    for (char c : magazine)
        count[c - 'a']++;

    for (char c : ransomNote) {
        if (count[c - 'a'] == 0)
            return false;
        count[c - 'a']--;
    }

    return true;
}

int main() {
    string ransomNote = "aa", magazine = "aba";

    cout << canConstruct(ransomNote, magazine) << endl;

    return 0;
}
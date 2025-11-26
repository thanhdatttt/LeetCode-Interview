// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> mp;

    // save to hashmap
    for (char c : s) 
        mp[c]++;

    // check string with hashmap
    for (char c : t) {
        mp[c]--;
        if (mp[c] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "anagram", t = "nagaram";
    
    cout << isAnagram(s, t) << endl;

    return 0;
}
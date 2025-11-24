// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while 
// preserving the order of characters. No two characters may map to the same character, 
// but a character may map to itself.

#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    // first solution use hash map for string to string
    // unordered_map<char, char> mp1, mp2;

    // for (int i = 0; i < s.size(); i++) {
    //     if (mp1.count(s[i]) && mp1[s[i]] != t[i])
    //         return false;
    //     if (mp2.count(t[i]) && mp2[t[i]] != s[i])
    //         return false;

    //     mp1[s[i]] = t[i];
    //     mp2[t[i]] = s[i];
    // }

    // return true;

    // second solution use normal array to store letters 
    char map_s[256] = {0};
    char map_t[256] = {0};

    for (int i = 0; i < s.size(); i++) {
        char char_c = s[i];
        char char_t = t[i];

        if (map_s[char_c] == 0 && map_t[char_t] == 0) {
            map_s[char_c] = char_t;
            map_t[char_t] = char_c;
        } else if (map_s[char_c] != char_t || map_t[char_t] != char_c) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "egg", t = "add";

    cout << isIsomorphic(s, t) << endl;
    return 0;
}
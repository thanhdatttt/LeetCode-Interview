// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string 
// by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    if (s == t) {
        return true;
    }

    int n = t.size(), m = s.size();
    int first = 0, second = 0;
    while (first < n && second < m) {
        if (t[first] == s[second]) {
            second++;
        }

        first++;
    }

    return second == m;
}

int main() {
    string t = "ahbgdc";
    string s = "abc";

    cout << isSubsequence(s, t) << endl;

    return 0;
}
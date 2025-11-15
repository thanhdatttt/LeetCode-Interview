// Given a string s, find the length of the longest substring without duplicate characters.

#include <iostream>
#include <vector>
using namespace std;

// dynamic window
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLen = 0;
    vector<int> count(256, 0);

    int left = 0;
    for (int right = 0; right < n; right++) {
        count[s[right]]++;

        while (count[s[right]] > 1) {
            count[s[left]]--;
            left++;
            
        }
        
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // int found = haystack.find(needle);
        // if (found != string :: npos)
        //     return found;
        // return -1;

        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0; // empty needle → index 0
        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++) {
            // Check substring haystack[i..i+m)
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i; // found match
        }

        return -1;
    }
};
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // first solutions
    // if (strs.empty())
    //     return "";
    
    // string prefix = strs[0];
    // for (int i = 1; i < strs.size(); i++) {
    //     while (strs[i].find(prefix) != 0) 
    //     {
    //         prefix.pop_back();
    //         if (prefix.empty())
    //             return "";
    //     }
    // }

    // return prefix;

    // second solution
    if (strs.empty())
        return "";

    sort(strs.begin(), strs.end());
    string first = strs.front();
    string last = strs.back();

    int i = 0;
    while (i <= first.size() && first[i] == last[i]) {
        i++;
    }

    return first.substr(0, i);
}

int main() {
    vector<string> strs = {"flower","flower","flower","flower"};

    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
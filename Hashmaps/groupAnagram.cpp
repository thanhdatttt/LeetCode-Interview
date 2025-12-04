// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        // sort the string to get the same type and store to hashmap
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &p : mp) {
        res.push_back(p.second);
    }

    return res;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "[\n";
    for (auto &group : ans) {
        cout << "  [ ";
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";
    return 0;
}
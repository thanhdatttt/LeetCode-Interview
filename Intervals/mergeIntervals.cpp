// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and 
// return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // sort the intervals
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    for (auto &it : intervals) {
        // push interval if empty or the end element of res interval < start element of current interval
        if (res.empty() || res.back()[1] < it[0]) {
            res.push_back(it);
        } else {
            // if end element of res interval > start element of current => update end element with current end element
            res.back()[1] = max(res.back()[1], it[1]);
        }
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> res = merge(intervals);

    for (auto& group : res) {
        cout << "[";
        for (auto& n : group) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
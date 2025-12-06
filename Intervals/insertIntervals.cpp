// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
// represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
// and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (newInterval.empty())
        return intervals;
    
    vector<vector<int>> res;
    if (intervals.empty()) {
        res.push_back(newInterval);
        return res;
    }

    int i = 0, n = intervals.size();
    // find the end element of intervals that bigger than start element of newInt
    while(i < n && intervals[i][1] < newInterval[0]) {
        // store the intervals that smaller
        res.push_back(intervals[i]);
        i++;
    }

    // insert and merge to the start element of intervals that bigger than end element of newInt
    while (i < n && intervals[i][0] <= newInterval[1]) {
        // update newInt with intervals
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res.push_back(newInterval);

    // store the rest of intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4, 8};

    vector<vector<int>> res = insert(intervals, newInterval);

    for (auto& group : res) {
        cout << "[";
        for (auto& n : group) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
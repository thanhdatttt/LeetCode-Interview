// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
// That is, each element of nums is covered by exactly one of the ranges, and there is no integer x 
// such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int n = nums.size();
    if (n == 0)
        return res;
    
    // start element of first string
    int start = nums[0];
    for (int i = 1; i < n; i++) {
        // if current element is not increment (nums[i - 1] is end element)
        if (nums[i] != nums[i - 1] + 1) {
            if (start == nums[i - 1]) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }

            // update new start element of new string
            start = nums[i];
        }
    }

    // update the rest of the array
    if (start == nums[n - 1]) {
        res.push_back(to_string(start));
    } else {
        res.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
    }

    return res;
}

int main() {
    vector<int> nums = {0,2,3,4,6,8,9};
    vector<string> res = summaryRanges(nums);

    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}
// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a subarray whose sum is greater than or equal to target. 
// If there is no such subarray, return 0 instead

#include <iostream>
#include <vector>
using namespace std;

// dynamic window
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0, minLen = __INT_MAX__;
    int left = 0;

    for (int right = 0; right < n; right++) {
        // sum each element
        sum += nums[right];

        // condition to move window
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            // move window to 1 element, minus that element
            sum -= nums[left];
            left++;
        } 
    }

    return minLen == __INT_MAX__ ? 0 : minLen;
}

int main () {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    cout << minSubArrayLen(7, nums) << endl;
    return 0;
}
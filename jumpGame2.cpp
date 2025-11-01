// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and i + j < n
// Return the minimum number of jumps to reach index n - 1. 
// The test cases are generated such that you can reach index n - 1.

#include <iostream>
#include <vector>
using namespace std;

int canJump2(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return 0;
    }

    int farthest = 0;
    int jump = 0;
    int currentEnd = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i+ nums[i]);
        if (i == currentEnd) {
            jump++;
            currentEnd = farthest;
        }
    }

    return jump;
}

int main() {
    vector<int> nums = {2,3,1,1,4};

    cout << canJump2(nums) << endl;

    return 0;
}
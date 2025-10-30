// You are given an integer array nums. You are initially positioned at the array's first index,
//  and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.
#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;
    int n = nums.size();
    if (n <= 1) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (i > farthest)
            return false;
        farthest = max(farthest, i + nums[i]);
        if (farthest >= n - 1)
            return true;
    }

    return true;
}

int main() {
    vector<int> nums = {3,2,1,0,4};

    cout << canJump(nums) << endl;

    return 0;
}
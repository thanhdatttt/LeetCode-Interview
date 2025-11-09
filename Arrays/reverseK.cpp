// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    // reverse takes begin and end - 1
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums, k);

    for(int n: nums) {
        cout << n << " ";
    }

    return 0;
}
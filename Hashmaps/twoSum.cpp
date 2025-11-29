// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];

        if (mp.count(need)) {
            return {mp[need], i};
        }

        // store elements in hashmap by their index
        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> res = twoSum(nums, target);

    for (int n : res) {
        cout << n << " ";
    }
    return 0;
}
// Given an integer array nums and an integer k, 
// return true if there are two distinct indices i and j in the array 
// such that nums[i] == nums[j] and abs(i - j) <= k

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // first solution using hashmap set and sliding window
    // unordered_set<int> mp;

    // for (int i = 0; i < nums.size(); i++) {
    //     if (mp.count(nums[i])) return true;

    //     mp.insert(nums[i]);

    //     if (mp.size() > k) {
    //         mp.erase(nums[i - k]);
    //     }
    // }

    // return false;

    // second solution using hashmap
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(nums[i])) {
            if (i - mp[nums[i]] <= k) {
                return true;
            }
        }

        mp[nums[i]] = i;
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 2};
    int k = 3;

    cout << containsNearbyDuplicate(nums, k) << endl;
    return 0;
}
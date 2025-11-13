// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end()); // Sort the array for 2 pointers
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = threeSum(nums);

    for (auto& v : res) {
        cout << "[" << v[0] << "," << v[1] << "," << v[2] << "]\n";
    }

    return 0;
}
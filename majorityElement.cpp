// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {

    int res = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            res = nums[i];
        }

        count += (nums[i] == res)? 1 : -1;
    }

    return res;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    // solution without using division
    int n = nums.size();
    vector<int> ans(n, 1);

    // cal prefix of nums[i] and asign (multiple all elements before nums[i] and asign to ans)
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = prefix;
        prefix *= nums[i];
    }

    // add suffix to ans (multiple all elements after nums[i] and add to ans)
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;

    // solution using division
    // int n = nums.size();
    // vector<int> ans(n, 1);

    // long long allProducts = 1;
    // int zeroCount = 0;
    // for (int i = 0; i < n; i++) {
    //     if (nums[i] == 0)
    //         zeroCount++;
    //     else 
    //         allProducts *= nums[i];
    // }

    // for (int i = 0; i < n; i++) {
    //     if (zeroCount > 1) 
    //         ans[i] = 0;
    //     else if (zeroCount == 1) {
    //         if (nums[i] == 0)
    //             ans[i] = allProducts;
    //         else 
    //             ans[i] = 0;
    //     } else {
    //         ans[i] = allProducts / nums[i];
    //     }
    // }

    // return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};

    vector<int> res = productExceptSelf(nums);
    for (int n : res) {
        cout << n << " ";
    }

    return 0;
}
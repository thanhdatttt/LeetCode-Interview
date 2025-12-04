// Given an unsorted array of integers nums, 
// return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    // first solution use unorder_set with O(n^2)
    // // store array is to hashmap
    // unordered_set<int> mp(nums.begin(), nums.end());
    // int longest = 0;

    // for (int i = 0; i < nums.size(); i++) {
    //     // start to count consetive if there is no number before it
    //     if (!mp.count(nums[i] - 1)) {
    //         int current = nums[i];
    //         int length = 1;

    //         // count to there is no number after it
    //         while (mp.count(current + 1)) {
    //             length++;
    //             current++;
    //         }

    //         longest = longest < length ? length : longest;
    //     }
    // }

    // return longest;

    // second solution use unorder_map 
    unordered_map<int, int> mp;
    int longest = 0;

    for (int n : nums) {
        // skip that already have in hashmap
        if (mp.count(n))
            continue;

        // find it left and right element key and get their value if have
        int left = mp.count(n - 1) ? mp[n - 1] : 0;
        int right = mp.count(n + 1) ? mp[n + 1] : 0;

        // store new length to element key
        int length = left + right + 1;
        mp[n] = length;

        // update new length to element from new length
        mp[n - left] = length;
        mp[n + right] = length;

        longest = max(longest, length);
    }

    return longest;
}

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    cout << longestConsecutive(nums) << endl;
    return 0;
}
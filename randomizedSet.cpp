// Implement the RandomizedSet class:

// RandomizedSet() Initializes the RandomizedSet object.
// bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
// bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
// int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
// You must implement the functions of the class such that each function works in average O(1) time complexity

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    private:
        vector<int> nums;
        unordered_map<int, int> index;

    public:
        RandomizedSet() {};

        bool insert(int value) {
            if (index.count(value))
                return false;

            nums.push_back(value);
            index[value] = nums.size() - 1;
            return true;
        }

        bool remove(int value) {
            if (!index.count(value)) 
                return false;
            
            // set current value with last value and pop last value
            auto it = index.find(value);
            nums[it->second] = nums.back();
            nums.pop_back();
            index[nums[it->second]] = it->second;
            index.erase(value);
            return true;
        }

        int getRandom() {
            return nums[rand() % nums.size()];
        }
};
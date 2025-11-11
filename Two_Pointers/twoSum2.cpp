// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
// find two numbers such that they add up to a specific target number. 
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, 
// added by one as an integer array [index1, index2] of length 2.

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        // sum 2 current elements
        int sum = numbers[left] + numbers[right];

        // if sum is target return
        if (sum == target) {
            return {left + 1, right + 1};
        }

        // if sum < target, need bigger else need smaller
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {};
}

int main() {
    vector<int> numbers = {-1,0};
    int target = -1;

    vector<int> res = twoSum(numbers, target);
    for (int n : res) {
        cout << n << " ";
    }

    return 0;
}
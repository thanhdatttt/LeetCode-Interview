// Given an integer array nums sorted in non-decreasing order, 
// remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​.
// After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. 
// The remaining elements beyond index k - 1 can be ignored.

#include<iostream>
#include<vector>
using namespace std;

void removeDuplicate(vector<int> &arr) {
    if (arr.empty()) return;

    int n = arr.size();
    int k = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    arr.resize(k);
}

int main() {
    vector<int> a = {0,0,1,1,1,2,2,3,3,4};

    removeDuplicate(a);

    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}
// Given an integer array nums sorted in non-decreasing order, 
// remove some duplicates in-place such that each unique element appears at most twice. 
// The relative order of the elements should be kept the same.

#include<iostream>
#include<vector>
using namespace std;

void removeDuplicate2(vector<int> &arr) {
    if (arr.size() <= 2) return;

    int n = arr.size();
    int k = 2;

    for (int i = 2; i < n; i++) {
        if (arr[i] != arr[k - 2]) {
            arr[k] = arr[i];
            k++;
        }
    }

    arr.resize(k);
}

int main() {
    vector<int> a = {1};

    removeDuplicate2(a);

    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}
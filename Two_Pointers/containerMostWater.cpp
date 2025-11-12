// You are given an integer array height of length n. 
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int maxArea = 0;
    while (left < right) {
        // calculate area
        int w = right - left;
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = w * h;

        // compare to get the max area
        if (maxArea < area) {
            maxArea = area;
        }

        // move to next element based on height
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << maxArea(height) << endl;

    return 0;
}
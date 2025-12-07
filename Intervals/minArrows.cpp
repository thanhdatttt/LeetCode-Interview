// There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
// The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] 
// denotes a balloon whose horizontal diameter stretches between xstart and xend. 
// You do not know the exact y-coordinates of the balloons.

// Arrows can be shot up directly vertically (in the positive y-direction) 
// from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend.
// There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

// Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }

    // sort by the end element of points
    sort(points.begin(), points.end(), [](const auto& a, const auto& b){
        return a[1] < b[1];
    });

    int arrow = 1;
    // shoot arrow from end element of first point
    int arrowPos = points[0][1];
    for (auto& point : points) {
        // if the start element of current point > arrow position 
        // => arrow cannot reach that point => need new arrow
        if (point[0] > arrowPos) {
            arrowPos = point[1];
            arrow++;
        }
    }

    return arrow;
}

int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    cout << findMinArrowShots(points) << endl;
    return 0;
}
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
// You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost,
// return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
// otherwise return -1. If there exists a solution, it is guaranteed to be unique.

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalGas = 0;
    int tank = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        int dif = gas[i] - cost[i];
        totalGas += dif;
        tank += dif;

        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    return totalGas >= 0 ? start : -1;
}

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. 
// You can only hold at most one share of the stock at any time. 
// However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

#include <iostream>
#include <vector>
using namespace std;

int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += (prices[i] - prices[i - 1]);
        }
    }

    return profit;
}

int main() {
    vector<int> prices = {1,2,3,4,5};

    cout << maxProfit2(prices) << endl;

    return 0;
}
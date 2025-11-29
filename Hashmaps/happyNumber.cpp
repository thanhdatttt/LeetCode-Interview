// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// -Starting with any positive integer, replace the number by the sum of the squares of its digits.
// -Repeat the process until the number equals 1 (where it will stay), 
// or it loops endlessly in a cycle which does not include 1.
// -Those numbers for which this process ends in 1 are happy.
// -Return true if n is a happy number, and false if not.

#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    while(n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    // first solution using hashmap
    unordered_set<int> seen;

    // loop to check whether the number have been seen
    while (n != 1 && !seen.count(n)) {
        // store the number into hashmap
        seen.insert(n);
        // calculate new number by num of square
        n = sumOfSquares(n);
    }

    // if the number is 1 -> true, if meet the seen number again -> false
    return n == 1;

    // second solution using slow–fast pointers
    // int slow = n;
    // int fast = sumOfSquares(n);

    // while (fast != 1 && slow != fast) {
    //     slow = sumOfSquares(slow);
    //     fast = sumOfSquares(sumOfSquares(fast));
    // }

    // return fast == 1;
}

int main() {
    int n = 19;

    cout << isHappy(n) << endl;
    return 0;
}
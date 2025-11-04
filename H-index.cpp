// Given an array of integers citations where citations[i] is 
// the number of citations a researcher received for their ith paper, return the researcher's h-index.

// The h-index is defined as the maximum value of h such that the given researcher has published at least h papers 
// that have each been cited at least h times.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    // first solution
    // sort array
    sort(citations.begin(), citations.end());
    int n = citations.size();

    // check which index value >= n - i
    for (int i = 0; i < n; i++) {
        int h = n - i;
        if (citations[i] >= h){
            return h;
        }
    }

    // return 0;

    // second solution
    // int  n = citations.size();
    // vector<int> count(n + 1, 0);

    // // count values of element and store in an array.
    // for (int i = 0; i < n; i++) {
    //     if (citations[i] >= n) {
    //         count[n]++;
    //     } else {
    //         count[citations[i]]++;
    //     }
    // }
    
    // // check from the end of count array , if sum of counts >= index i then sum of counts is h index
    // int papers = 0;
    // for (int i = n; i >= 0; i--) {
    //     papers += count[i];
    //     if (papers >= i) {
    //         return papers;
    //     }
    // }

    // return 0;
}

int main() {
    vector<int> citations = {3,0,6,1,5};

    cout << hIndex(citations) << endl;
    return 0;
}
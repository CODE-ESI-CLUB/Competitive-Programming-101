// Sample Solution: General Contest Problem
// Problem: Find the maximum subarray sum (Kadane's Algorithm)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long kadane(const vector<int>& arr) {
    long long max_so_far = arr[0];
    long long max_ending_here = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        max_ending_here = max((long long)arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << kadane(arr) << endl;
    
    return 0;
}

/*
Sample Input:
9
-2 1 -3 4 -1 2 1 -5 4

Sample Output:
6

Explanation: Maximum subarray is [4, -1, 2, 1] with sum 6

Time Complexity: O(n)
Space Complexity: O(1)
*/
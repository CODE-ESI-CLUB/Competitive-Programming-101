// Sample Solution: Basic Sorting Problem
// Problem: Sort an array of integers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Output sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Sample Input:
5
3 1 4 1 5

Sample Output:
1 1 3 4 5

Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary space
*/
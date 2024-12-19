#include <bits/stdc++.h>
using namespace std;

int main() {
    int case_num = 1; 

    while (true) {
        int n; 
        if (!(cin >> n)) break;  

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int m; 
        cin >> m;
        cout << "Case " << case_num << ":\n";

        for (int i = 0; i < m; i++) {
            int q; 
            cin >> q;
            int ans = INT_MAX;  
            int min_diff = INT_MAX;

            
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {  
                    int sum = arr[j] + arr[k];
                    int diff = abs(sum - q);
                    
                
                    if (diff < min_diff) {
                        min_diff = diff;
                        ans = sum;
                    }
                }
            }
            cout << "Closest sum to " << q << " is " << ans << ".\n";
        }
        case_num++;  
    }

    return 0;
}

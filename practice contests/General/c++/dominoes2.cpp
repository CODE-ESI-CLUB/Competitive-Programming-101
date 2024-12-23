#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int domino, vector<vector<int>>& adj, set<int>& fallen) {
    // If this domino has already fallen, return
    if (fallen.find(domino) != fallen.end()) {
        return;
    }
    
    // Mark this domino as fallen
    fallen.insert(domino);
    
    // Recursively process all dominoes that this one knocks down
    for (int next : adj[domino]) {
        dfs(next, adj, fallen);
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        int n, m, l;
        cin >> n >> m >> l;
        
        // Create adjacency list for domino relationships
        vector<vector<int>> adj(n + 1);  // 1-based indexing
        
        // Read domino relationships
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        
        // Keep track of fallen dominoes
        set<int> fallen;
        
        // Process each hand-knocked domino
        for (int i = 0; i < l; i++) {
            int z;
            cin >> z;
            dfs(z, adj, fallen);
        }
        
        // Output total number of fallen dominoes
        cout << fallen.size() << endl;
    }
    
    return 0;
}
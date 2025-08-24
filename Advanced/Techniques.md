# Advanced Competitive Programming Techniques

Welcome to the **Advanced Techniques** guide! 🚀 This section covers sophisticated algorithms and techniques used in high-level competitive programming contests.

---

## Table of Contents

1. [Advanced Graph Algorithms](#advanced-graph-algorithms)
2. [Advanced Dynamic Programming](#advanced-dynamic-programming)
3. [String Algorithms](#string-algorithms)
4. [Mathematical Techniques](#mathematical-techniques)
5. [Advanced Data Structures](#advanced-data-structures)
6. [Network Flow](#network-flow)
7. [Optimization Techniques](#optimization-techniques)

---

## Advanced Graph Algorithms

### 1. Articulation Points and Bridges

**Articulation Points:** Vertices whose removal increases the number of connected components.

```cpp
class ArticulationPoints {
    vector<vector<int>> adj;
    vector<bool> visited, ap;
    vector<int> disc, low, parent;
    int timer;
    
    void bridgeUtil(int u) {
        visited[u] = true;
        disc[u] = low[u] = ++timer;
        int children = 0;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                bridgeUtil(v);
                
                low[u] = min(low[u], low[v]);
                
                // Root with 2+ children OR non-root with low[v] >= disc[u]
                if ((parent[u] == -1 && children > 1) || 
                    (parent[u] != -1 && low[v] >= disc[u]))
                    ap[u] = true;
            }
            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }
    
public:
    vector<int> findArticulationPoints(int n) {
        adj.resize(n); visited.resize(n); ap.resize(n);
        disc.resize(n); low.resize(n); parent.resize(n, -1);
        timer = 0;
        
        for (int i = 0; i < n; i++)
            if (!visited[i])
                bridgeUtil(i);
        
        vector<int> result;
        for (int i = 0; i < n; i++)
            if (ap[i]) result.push_back(i);
        return result;
    }
};
```

### 2. Strongly Connected Components (Kosaraju's Algorithm)

```cpp
class SCC {
    vector<vector<int>> adj, radj;
    vector<bool> visited;
    stack<int> st;
    
    void dfs1(int v) {
        visited[v] = true;
        for (int u : adj[v])
            if (!visited[u])
                dfs1(u);
        st.push(v);
    }
    
    void dfs2(int v, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        for (int u : radj[v])
            if (!visited[u])
                dfs2(u, component);
    }
    
public:
    vector<vector<int>> findSCC(int n) {
        adj.resize(n); radj.resize(n); visited.resize(n);
        
        // Step 1: Fill vertices in stack by DFS finish time
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs1(i);
        
        // Step 2: Process in reverse finish time order
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> components;
        
        while (!st.empty()) {
            int v = st.top(); st.pop();
            if (!visited[v]) {
                vector<int> component;
                dfs2(v, component);
                components.push_back(component);
            }
        }
        return components;
    }
};
```

### 3. Heavy-Light Decomposition

```cpp
class HLD {
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    
    int dfs(int v) {
        int size = 1, max_child_size = 0;
        for (int u : adj[v]) {
            if (u != parent[v]) {
                parent[u] = v;
                depth[u] = depth[v] + 1;
                int child_size = dfs(u);
                if (child_size > max_child_size) {
                    max_child_size = child_size;
                    heavy[v] = u;
                }
                size += child_size;
            }
        }
        return size;
    }
    
    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (int u : adj[v]) {
            if (u != parent[v] && u != heavy[v])
                decompose(u, u);
        }
    }
    
public:
    void build(int n, int root) {
        adj.resize(n); parent.resize(n); depth.resize(n);
        heavy.resize(n, -1); head.resize(n); pos.resize(n);
        cur_pos = 0;
        
        dfs(root);
        decompose(root, root);
    }
    
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]])
                u = parent[head[u]];
            else
                v = parent[head[v]];
        }
        return depth[u] < depth[v] ? u : v;
    }
};
```

---

## Advanced Dynamic Programming

### 1. DP on Trees

```cpp
// Example: Tree diameter using DP
class TreeDP {
    vector<vector<int>> adj;
    vector<int> dp;
    int diameter;
    
    void dfs(int v, int parent) {
        vector<int> child_distances;
        
        for (int u : adj[v]) {
            if (u != parent) {
                dfs(u, v);
                child_distances.push_back(dp[u]);
            }
        }
        
        dp[v] = 0;
        for (int dist : child_distances)
            dp[v] = max(dp[v], dist + 1);
        
        if (child_distances.size() >= 2) {
            sort(child_distances.rbegin(), child_distances.rend());
            diameter = max(diameter, child_distances[0] + child_distances[1] + 2);
        } else if (child_distances.size() == 1) {
            diameter = max(diameter, child_distances[0] + 1);
        }
    }
    
public:
    int findDiameter(int n) {
        adj.resize(n); dp.resize(n);
        diameter = 0;
        dfs(0, -1);
        return diameter;
    }
};
```

### 2. Digit DP

```cpp
// Count numbers with at most K different digits in range [L, R]
class DigitDP {
    string num;
    int K;
    vector<vector<vector<vector<int>>>> memo;
    
    int solve(int pos, int mask, bool tight, bool started) {
        if (pos == num.length())
            return started && __builtin_popcount(mask) <= K;
        
        if (memo[pos][mask][tight][started] != -1)
            return memo[pos][mask][tight][started];
        
        int limit = tight ? (num[pos] - '0') : 9;
        int result = 0;
        
        for (int digit = 0; digit <= limit; digit++) {
            bool new_tight = tight && (digit == limit);
            bool new_started = started || (digit > 0);
            int new_mask = mask;
            
            if (new_started)
                new_mask |= (1 << digit);
            
            if (__builtin_popcount(new_mask) <= K)
                result += solve(pos + 1, new_mask, new_tight, new_started);
        }
        
        return memo[pos][mask][tight][started] = result;
    }
    
public:
    int countNumbers(string number, int k) {
        num = number;
        K = k;
        memo.assign(num.length(), vector<vector<vector<int>>>(
            1024, vector<vector<int>>(2, vector<int>(2, -1))));
        return solve(0, 0, true, false);
    }
};
```

### 3. DP with Bitmasks

```cpp
// Traveling Salesman Problem
class TSP {
    vector<vector<int>> dist;
    vector<vector<int>> dp;
    int n;
    
public:
    int solveTSP(vector<vector<int>>& distances) {
        n = distances.size();
        dist = distances;
        dp.assign(1 << n, vector<int>(n, -1));
        
        return solve(1, 0);  // Start from city 0
    }
    
private:
    int solve(int mask, int pos) {
        if (mask == (1 << n) - 1)
            return dist[pos][0];  // Return to starting city
        
        if (dp[mask][pos] != -1)
            return dp[mask][pos];
        
        int result = INT_MAX;
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int new_cost = dist[pos][city] + solve(mask | (1 << city), city);
                result = min(result, new_cost);
            }
        }
        
        return dp[mask][pos] = result;
    }
};
```

---

## String Algorithms

### 1. KMP Algorithm

```cpp
class KMP {
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
        return lps;
    }
    
public:
    vector<int> search(const string& text, const string& pattern) {
        vector<int> result;
        vector<int> lps = computeLPS(pattern);
        int n = text.length(), m = pattern.length();
        int i = 0, j = 0;
        
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++; j++;
            }
            
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return result;
    }
};
```

### 2. Z Algorithm

```cpp
vector<int> zFunction(const string& s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
```

---

## Mathematical Techniques

### 1. Matrix Exponentiation

```cpp
class MatrixExponentiation {
    using Matrix = vector<vector<long long>>;
    const int MOD = 1000000007;
    
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    
public:
    Matrix matrixPower(Matrix base, long long n) {
        int size = base.size();
        Matrix result(size, vector<long long>(size, 0));
        
        // Initialize as identity matrix
        for (int i = 0; i < size; i++)
            result[i][i] = 1;
        
        while (n > 0) {
            if (n & 1)
                result = multiply(result, base);
            base = multiply(base, base);
            n >>= 1;
        }
        return result;
    }
    
    // Example: Fibonacci using matrix exponentiation
    long long fibonacci(long long n) {
        if (n <= 1) return n;
        
        Matrix base = {{1, 1}, {1, 0}};
        Matrix result = matrixPower(base, n - 1);
        return result[0][0];
    }
};
```

### 2. Number Theory Advanced

```cpp
// Extended Euclidean Algorithm
pair<long long, long long> extgcd(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto [x1, y1] = extgcd(b, a % b);
    return {y1, x1 - (a / b) * y1};
}

// Modular Inverse
long long modinv(long long a, long long m) {
    auto [x, y] = extgcd(a, m);
    return (x % m + m) % m;
}

// Chinese Remainder Theorem
long long crt(vector<long long>& a, vector<long long>& m) {
    long long result = 0, M = 1;
    for (int i = 0; i < a.size(); i++) M *= m[i];
    
    for (int i = 0; i < a.size(); i++) {
        long long Mi = M / m[i];
        result = (result + a[i] * Mi % M * modinv(Mi, m[i]) % M) % M;
    }
    return result;
}
```

---

## Advanced Data Structures

### 1. Segment Tree with Lazy Propagation

```cpp
class LazySegmentTree {
    vector<long long> tree, lazy;
    int n;
    
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void updateRange(int node, int start, int end, int l, int r, long long val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return;
        
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        
        propagate(2 * node, start, mid);
        propagate(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    long long queryRange(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;
        
        propagate(node, start, end);
        
        if (start >= l && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) +
               queryRange(2 * node + 1, mid + 1, end, l, r);
    }
    
public:
    LazySegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }
    
    void updateRange(int l, int r, long long val) {
        updateRange(1, 0, n - 1, l, r, val);
    }
    
    long long queryRange(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
```

### 2. Fenwick Tree (Binary Indexed Tree)

```cpp
class FenwickTree {
    vector<long long> bit;
    int n;
    
public:
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}
    
    void update(int idx, long long val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    
    long long sum(int idx) {
        long long sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
    
    long long rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    // Binary search on Fenwick Tree
    int lowerBound(long long target) {
        int pos = 0;
        for (int pw = 1 << 20; pw > 0; pw >>= 1) {
            if (pos + pw <= n && bit[pos + pw] < target) {
                target -= bit[pos + pw];
                pos += pw;
            }
        }
        return pos;
    }
};
```

---

## Network Flow

### 1. Dinic's Algorithm (Maximum Flow)

```cpp
class Dinic {
    struct Edge {
        int to, cap, flow;
    };
    
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<int> level, iter;
    int n;
    
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (level[edges[id].to] < 0 && edges[id].flow < edges[id].cap) {
                    level[edges[id].to] = level[v] + 1;
                    q.push(edges[id].to);
                }
            }
        }
    }
    
    int dfs(int v, int t, int pushed) {
        if (v == t || pushed == 0)
            return pushed;
        
        for (int& cid = iter[v]; cid < adj[v].size(); cid++) {
            int id = adj[v][cid];
            int to = edges[id].to;
            
            if (level[v] + 1 != level[to] || edges[id].cap <= edges[id].flow)
                continue;
            
            int tr = dfs(to, t, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    
public:
    Dinic(int n) : n(n), adj(n), level(n), iter(n) {}
    
    void addEdge(int from, int to, int cap) {
        adj[from].push_back(edges.size());
        edges.push_back({to, cap, 0});
        adj[to].push_back(edges.size());
        edges.push_back({from, 0, 0});
    }
    
    long long maxflow(int s, int t) {
        long long flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) break;
            fill(iter.begin(), iter.end(), 0);
            while (int pushed = dfs(s, t, INT_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
```

---

## Optimization Techniques

### 1. Coordinate Compression

```cpp
class CoordinateCompression {
    vector<int> vals;
    
public:
    void add(int x) {
        vals.push_back(x);
    }
    
    void compress() {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }
    
    int get(int x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }
    
    int original(int compressed_idx) {
        return vals[compressed_idx];
    }
    
    int size() {
        return vals.size();
    }
};
```

### 2. Square Root Decomposition

```cpp
class SqrtDecomposition {
    vector<int> arr, blocks;
    int n, sqrt_n;
    
public:
    SqrtDecomposition(const vector<int>& a) {
        arr = a;
        n = arr.size();
        sqrt_n = sqrt(n) + 1;
        blocks.resize(sqrt_n);
        
        for (int i = 0; i < n; i++)
            blocks[i / sqrt_n] += arr[i];
    }
    
    void update(int idx, int val) {
        blocks[idx / sqrt_n] += val - arr[idx];
        arr[idx] = val;
    }
    
    int query(int l, int r) {
        int sum = 0;
        int c_l = l / sqrt_n, c_r = r / sqrt_n;
        
        if (c_l == c_r) {
            for (int i = l; i <= r; i++)
                sum += arr[i];
        } else {
            for (int i = l; i < (c_l + 1) * sqrt_n; i++)
                sum += arr[i];
            for (int i = c_l + 1; i < c_r; i++)
                sum += blocks[i];
            for (int i = c_r * sqrt_n; i <= r; i++)
                sum += arr[i];
        }
        return sum;
    }
};
```

---

## Practice Problems by Topic

### Advanced Graph Algorithms
1. **Articulation Points:** [SPOJ SUBMERGE](https://www.spoj.com/problems/SUBMERGE/)
2. **SCC:** [Codeforces 427C - Checkposts](https://codeforces.com/contest/427/problem/C)
3. **Heavy-Light Decomposition:** [SPOJ QTREE](https://www.spoj.com/problems/QTREE/)

### Advanced DP
1. **Tree DP:** [Codeforces 1249F - Maximum Weight Subset](https://codeforces.com/contest/1249/problem/F)
2. **Digit DP:** [SPOJ GONE - How Many Numbers?](https://www.spoj.com/problems/GONE/)
3. **Bitmask DP:** [Codeforces 1185G1 - Playlist for Polycarp](https://codeforces.com/contest/1185/problem/G1)

### String Algorithms
1. **KMP:** [Codeforces 126B - Password](https://codeforces.com/contest/126/problem/B)
2. **Z Algorithm:** [Codeforces 432D - Prefixes and Suffixes](https://codeforces.com/contest/432/problem/D)

### Mathematical Techniques
1. **Matrix Exponentiation:** [SPOJ SEQ - Recursive Sequence](https://www.spoj.com/problems/SEQ/)
2. **Number Theory:** [Codeforces 17A - Noldbach Problem](https://codeforces.com/contest/17/problem/A)

### Network Flow
1. **Maximum Flow:** [Codeforces 653E - Bear and Forgotten Tree 2](https://codeforces.com/contest/653/problem/E)
2. **Minimum Cut:** [SPOJ FASTFLOW](https://www.spoj.com/problems/FASTFLOW/)

---

## Time Complexity Summary

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Articulation Points | O(V + E) | O(V + E) |
| SCC (Kosaraju) | O(V + E) | O(V + E) |
| Heavy-Light Decomposition | O(N log N) preprocessing, O(log² N) query | O(N) |
| Matrix Exponentiation | O(K³ log N) | O(K²) |
| Segment Tree with Lazy | O(log N) query/update | O(N) |
| Dinic's Algorithm | O(V²E) | O(V + E) |
| Square Root Decomposition | O(√N) query/update | O(N) |

---

## 🎯 Tips for Implementation

### 1. Template for Competitive Programming
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int INF = 1e9;
const ll LLINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Your code here
    
    return 0;
}
```

### 2. Debugging Macros
```cpp
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#else
#define debug(x)
#define debug2(x, y)
#endif
```

---

## 📚 Advanced Resources

- **Research Papers:**
  - "Range Minimum Queries in Logarithmic Time with Linear Space" - Bender & Farach-Colton
  - "The LCA Problem Revisited" - Bender et al.

- **Advanced Courses:**
  - MIT 6.046J - Design and Analysis of Algorithms
  - Stanford CS261 - Optimization and Algorithmic Paradigms

- **Contest Archives:**
  - [Codeforces Problemset](https://codeforces.com/problemset) (sorted by difficulty)
  - [AtCoder Problems](https://atcoder.jp/contests/archive) (high-quality problems)
  - [ICPC World Finals Problems](https://icpc.global/) (ultimate challenge)

---

**These advanced techniques form the foundation for tackling the most challenging competitive programming problems. Master them through consistent practice and implementation! 🚀**
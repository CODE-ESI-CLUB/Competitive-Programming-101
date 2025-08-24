# Advanced Problem Set 1: Complex Algorithms & Data Structures

This set covers advanced competitive programming topics including advanced DP, string algorithms, and complex data structures.

---

## Problem 1: Persistent Segment Tree
**Statement**: Implement a persistent segment tree that maintains all versions after updates.

**Operations**:
- Update position i to value v in version k
- Query sum in range [l, r] in version k

**Input**: 
- N (array size), M (operations)
- Initial array
- M operations: UPDATE i v k or QUERY l r k

**Output**: For each query, output the sum.

**Time Complexity**: O(log N) per operation, O(N log N) space.

---

## Problem 2: Heavy-Light Decomposition
**Statement**: Answer path queries on a tree efficiently.

**Operations**:
- Update value at node v
- Query maximum value on path from u to v

**Input**: 
- N nodes, initial values
- Tree edges
- M operations

**Output**: Answer for each query.

**Time Complexity**: O(log² N) per operation.

---

## Problem 3: Suffix Array with LCP
**Statement**: Build suffix array and LCP array for string processing.

**Input**: String S (|S| ≤ 10⁵)

**Output**: 
- Suffix array
- LCP array

**Applications**: Longest repeated substring, number of distinct substrings.

**Example**:
```
Input: "banana"
Suffix Array: [5, 3, 1, 0, 4, 2]
LCP Array: [0, 1, 3, 0, 0, 2]
```

---

## Problem 4: Aho-Corasick Algorithm
**Statement**: Find all occurrences of multiple patterns in a text.

**Input**: 
- K pattern strings
- Text string T

**Output**: All positions where any pattern occurs.

**Example**:
```
Patterns: ["he", "she", "his", "hers"]
Text: "ushers"
Output: 
- "she" at position 1
- "he" at position 2
- "hers" at position 2
```

**Time Complexity**: O(|T| + sum of |patterns|)

---

## Problem 5: Matrix Chain Multiplication (Advanced DP)
**Statement**: Find minimum scalar multiplications to compute matrix chain product.

**Input**: 
- N matrices with dimensions
- Chain: A₁ × A₂ × ... × Aₙ

**Output**: Minimum multiplications needed.

**Recurrence**: 
dp[i][j] = min(dp[i][k] + dp[k+1][j] + cost(i,k,j)) for all k

**Example**:
```
Input: Matrices with dimensions [(1,2), (2,3), (3,4), (4,5)]
Output: 30
```

---

## Problem 6: Convex Hull Trick (DP Optimization)
**Statement**: Optimize DP with linear functions using convex hull.

**Problem Type**: DP where transition involves min/max of linear functions.

**Template**:
```
dp[i] = min(dp[j] + a[j] * x[i] + b[j]) for all j < i
```

**Example Application**: 
- Building fences with cost optimization
- Scheduling with linear penalties

**Time Complexity**: O(N log N) or O(N) with deque optimization.

---

## Problem 7: Maximum Flow with Min Cost
**Statement**: Find maximum flow with minimum cost in flow network.

**Input**: 
- Flow network with capacities and costs
- Source and sink

**Output**: Maximum flow value and minimum cost.

**Algorithm**: Successive shortest paths or cycle canceling.

**Applications**: Assignment problems, transportation problems.

---

## Problem 8: Palindromic Tree (Eertree)
**Statement**: Build palindromic tree for string and answer queries.

**Operations**:
- Count distinct palindromic substrings
- Count occurrences of palindromic substring
- Find longest palindromic suffix

**Input**: String S (|S| ≤ 10⁵)

**Output**: Answers to queries.

**Properties**: At most |S|+1 nodes, linear time construction.

---

## Problem 9: Link-Cut Tree
**Statement**: Maintain forest of rooted trees with link/cut operations.

**Operations**:
- Link(u, v): Make u parent of v
- Cut(u): Cut edge between u and its parent  
- Query path aggregates (sum, max, etc.)

**Time Complexity**: O(log N) per operation.

**Applications**: Dynamic connectivity, LCA in changing trees.

---

## Problem 10: Fast Walsh-Hadamard Transform (FWHT)
**Statement**: Compute XOR/OR/AND convolution efficiently.

**Problem**: Given arrays A, B, compute C where:
```
C[k] = Σ A[i] * B[j] where i op j = k
op ∈ {XOR, OR, AND}
```

**Time Complexity**: O(N log N) where N = 2ᵏ

**Applications**: Subset sum DP, bitmask DP optimization.

---

## Problem 11: 2D Range Tree
**Statement**: Answer 2D range queries efficiently.

**Operations**:
- Update point (x, y) to value v
- Query sum in rectangle [x₁, x₂] × [y₁, y₂]

**Time Complexity**: O(log² N) per operation.

**Space Complexity**: O(N log N)

---

## Problem 12: Suffix Automaton
**Statement**: Build suffix automaton for string matching queries.

**Properties**:
- At most 2N-1 states
- At most 3N-2 transitions
- Linear time construction

**Applications**:
- Count distinct substrings
- Find k-th lexicographically smallest substring
- Multiple string matching

---

## Problem 13: Centroid Decomposition
**Statement**: Decompose tree into centroid hierarchy for path queries.

**Applications**:
- Count paths with specific properties
- Distance queries in tree
- Path updates and queries

**Time Complexity**: O(N log N) preprocessing, O(log N) query.

**Template Structure**:
```cpp
void centroid_decompose(int v) {
    int centroid = find_centroid(v);
    // Process all paths through centroid
    mark_processed(centroid);
    for (child : children[centroid]) {
        if (!processed[child]) {
            centroid_decompose(child);
        }
    }
}
```

---

## Problem 14: Dynamic Programming on Trees (Advanced)
**Statement**: Solve complex DP problems on tree structures.

**Example Problems**:
- Maximum independent set in tree
- Tree diameter with edge weights
- Minimum dominating set
- Tree coloring problems

**Template**:
```cpp
void tree_dp(int v, int parent) {
    dp[v][0] = base_case_0;
    dp[v][1] = base_case_1;
    
    for (int u : adj[v]) {
        if (u != parent) {
            tree_dp(u, v);
            // Combine child results
            dp[v][0] = combine(dp[v][0], dp[u][...]);
            dp[v][1] = combine(dp[v][1], dp[u][...]);
        }
    }
}
```

---

## Problem 15: String Hashing with Rolling Hash
**Statement**: Implement robust string hashing for pattern matching.

**Double Hashing Template**:
```cpp
const int P1 = 31, P2 = 37;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

pair<int,int> compute_hash(string s) {
    int h1 = 0, h2 = 0;
    int p1 = 1, p2 = 1;
    for (char c : s) {
        h1 = (h1 + (c - 'a' + 1) * p1) % MOD1;
        h2 = (h2 + (c - 'a' + 1) * p2) % MOD2;
        p1 = (p1 * P1) % MOD1;
        p2 = (p2 * P2) % MOD2;
    }
    return {h1, h2};
}
```

**Applications**: Substring matching, longest common substring.

---

## Problem 16: Advanced Graph Algorithms

### 16a: Chinese Postman Problem
Find minimum cost tour that visits every edge at least once.

### 16b: Maximum Bipartite Matching with Kuhn's Algorithm
```cpp
bool kuhn(int v) {
    for (int to : adj[v]) {
        if (used[to]) continue;
        used[to] = true;
        if (match[to] == -1 || kuhn(match[to])) {
            match[to] = v;
            return true;
        }
    }
    return false;
}
```

### 16c: 2-SAT Problem
Determine satisfiability of boolean formula in CNF with 2 literals per clause.

---

## Implementation Guidelines:

### Memory Management:
- Use vectors instead of arrays when possible
- Be careful with memory limits in contests
- Consider space complexity of algorithms

### Time Optimization:
- Profile bottlenecks in complex algorithms
- Use fast I/O for large inputs
- Consider cache-friendly implementations

### Debugging Advanced Structures:
- Test with small examples first
- Verify invariants at each step
- Use visualization tools when available

### Contest Strategy:
- Implement simpler version first
- Have template code ready
- Practice implementation under time pressure

---

## Recommended Practice Platforms:

1. **Codeforces**: Advanced algorithmic problems
2. **AtCoder**: High-quality problem sets
3. **CodeChef**: Long contests for practice
4. **SPOJ**: Classical problems for each algorithm
5. **TopCoder**: SRM archives

---

## Time Complexity Summary:

| Data Structure/Algorithm | Preprocessing | Query/Update |
|-------------------------|---------------|--------------|
| Persistent Segment Tree | O(N) | O(log N) |
| Heavy-Light Decomposition | O(N) | O(log² N) |
| Suffix Array + LCP | O(N log N) | O(log N) |
| Link-Cut Tree | - | O(log N) |
| Centroid Decomposition | O(N log N) | O(log N) |
| 2D Range Tree | O(N log N) | O(log² N) |

---

**Master these advanced techniques to excel in high-level competitive programming contests! 🏆**
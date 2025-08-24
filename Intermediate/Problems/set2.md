# Intermediate Problem Set 2: Graph Algorithms & Trees

This set focuses on intermediate graph problems and tree structures.

---

## Problem 1: BFS Shortest Path (Unweighted Graph)
**Statement**: Find the shortest path between two vertices in an unweighted graph.

**Input**: 
- N vertices, M edges
- M lines with edges (u, v)
- Source and destination vertices

**Output**: Shortest distance, or -1 if no path exists.

**Example**:
```
Input:
5 6
1 2
1 3
2 4
3 4
4 5
2 5
2 5
Output: 2
```

**Algorithm**: Use BFS with queue.

---

## Problem 2: Tree Diameter
**Statement**: Find the diameter (longest path) of a tree.

**Input**: 
- N vertices
- N-1 edges representing tree structure

**Output**: Length of the diameter.

**Example**:
```
Input:
6
1 2
2 3
2 4
4 5
4 6
Output: 4
```

**Solution Approach**: 
1. Find farthest node from any node using BFS
2. Find farthest node from the result of step 1

---

## Problem 3: Topological Sort
**Statement**: Perform topological sorting on a DAG (Directed Acyclic Graph).

**Input**: 
- N vertices, M directed edges
- M lines with edges (u, v) meaning u → v

**Output**: Any valid topological ordering.

**Example**:
```
Input:
6 6
5 2
5 0
4 0
4 1
2 3
3 1
Output: 5 4 2 3 1 0
```

**Algorithm**: Use Kahn's algorithm or DFS-based approach.

---

## Problem 4: Connected Components
**Statement**: Count the number of connected components in an undirected graph.

**Input**: 
- N vertices, M edges
- M lines with edges (u, v)

**Output**: Number of connected components.

**Example**:
```
Input:
7 4
1 2
2 3
4 5
6 7
Output: 3
```

**Components**: {1,2,3}, {4,5}, {6,7}

---

## Problem 5: Binary Tree Level Order Traversal
**Statement**: Print nodes of binary tree level by level.

**Input**: Binary tree structure (implement input parsing as needed).

**Output**: Nodes printed level by level.

**Example**:
```
Tree:       3
          /   \
         9     20
              /  \
             15   7

Output: 
Level 0: 3
Level 1: 9 20
Level 2: 15 7
```

---

## Problem 6: Minimum Spanning Tree (Kruskal's)
**Statement**: Find the minimum cost to connect all vertices in a weighted graph.

**Input**: 
- N vertices, M edges
- M lines with edges (u, v, weight)

**Output**: Minimum spanning tree cost.

**Example**:
```
Input:
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Output: 19
```

**Algorithm**: Sort edges by weight, use Union-Find to detect cycles.

---

## Problem 7: Binary Search Tree Operations
**Statement**: Implement insert, search, and delete in BST.

**Input**: 
- N operations
- Each operation: INSERT x, SEARCH x, or DELETE x

**Output**: For each SEARCH, print "FOUND" or "NOT FOUND".

**Example**:
```
Input:
INSERT 5
INSERT 3
INSERT 7
SEARCH 3
SEARCH 6
DELETE 3
SEARCH 3
Output:
FOUND
NOT FOUND
NOT FOUND
```

---

## Problem 8: Graph Cycle Detection (Undirected)
**Statement**: Detect if an undirected graph contains a cycle.

**Input**: 
- N vertices, M edges
- M lines with edges (u, v)

**Output**: "YES" if cycle exists, "NO" otherwise.

**Example**:
```
Input:
4 4
1 2
2 3
3 4
4 1
Output: YES
```

**Methods**: DFS with parent tracking or Union-Find.

---

## Problem 9: Lowest Common Ancestor (LCA)
**Statement**: Find LCA of two nodes in a binary tree.

**Input**: 
- Binary tree structure
- Two node values p and q

**Output**: Value of LCA node.

**Example**:
```
Tree:       3
          /   \
         5     1
        / \   / \
       6   2 0   8
          / \
         7   4

Query: LCA(5, 1) = 3
Query: LCA(5, 4) = 5
```

---

## Problem 10: Graph Bipartiteness Check
**Statement**: Check if a graph is bipartite (can be colored with 2 colors).

**Input**: 
- N vertices, M edges
- M lines with edges (u, v)

**Output**: "YES" if bipartite, "NO" otherwise.

**Example**:
```
Input:
4 4
1 2
2 3
3 4
4 1
Output: YES
```

**Algorithm**: Use BFS/DFS coloring. If adjacent nodes have same color, not bipartite.

---

## Problem 11: Binary Tree Maximum Path Sum
**Statement**: Find maximum sum path in binary tree (path can start/end at any node).

**Input**: Binary tree with node values (can be negative).

**Output**: Maximum path sum.

**Example**:
```
Tree:   1
       / \
      2   3
Output: 6 (path: 2 -> 1 -> 3)
```

---

## Problem 12: Graph Shortest Path (Dijkstra's)
**Statement**: Find shortest paths from source to all vertices in weighted graph.

**Input**: 
- N vertices, M edges
- M lines with edges (u, v, weight)
- Source vertex

**Output**: Distance to each vertex (or -1 if unreachable).

**Example**:
```
Input:
5 7
0 1 4
0 2 1
1 3 1
2 1 2
2 4 5
3 4 3
1 4 1
0
Output:
0: 0
1: 3
2: 1
3: 4
4: 6
```

---

## Problem 13: Tree Traversals
**Statement**: Given inorder and preorder traversals, reconstruct the binary tree.

**Input**: 
- N (number of nodes)
- Preorder traversal
- Inorder traversal

**Output**: Postorder traversal of the reconstructed tree.

**Example**:
```
Input:
4
3 9 20 15 7
9 3 15 20 7
Output: 9 15 7 20 3
```

---

## Problem 14: Floyd-Warshall (All Pairs Shortest Path)
**Statement**: Find shortest distances between all pairs of vertices.

**Input**: 
- N vertices
- Adjacency matrix (use large value for no edge)

**Output**: Distance matrix.

**Time Complexity**: O(N³)

---

## Problem 15: Strongly Connected Components
**Statement**: Find all strongly connected components in a directed graph.

**Input**: 
- N vertices, M directed edges
- M lines with edges (u, v)

**Output**: Number of strongly connected components.

**Algorithm**: Kosaraju's or Tarjan's algorithm.

---

## Implementation Tips:

### Graph Representation:
```cpp
// Adjacency List
vector<vector<int>> adj(n);
adj[u].push_back(v);

// For weighted graphs
vector<vector<pair<int,int>>> adj(n);
adj[u].push_back({v, weight});
```

### DFS Template:
```cpp
vector<bool> visited(n);
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}
```

### BFS Template:
```cpp
vector<int> dist(n, -1);
queue<int> q;
dist[start] = 0;
q.push(start);

while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (dist[u] == -1) {
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}
```

### Union-Find Template:
```cpp
vector<int> parent(n);
for (int i = 0; i < n; i++) parent[i] = i;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}
```

---

**These problems will strengthen your graph and tree algorithm skills! 🌳**
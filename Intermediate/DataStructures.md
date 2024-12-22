# Intermediate Data Structures Guide

## Table of Contents
1. [Binary Trees](#binary-trees)
2. [Binary Search Trees (BST)](#binary-search-trees)
3. [AVL Trees](#avl-trees)
4. [Heap/Priority Queue](#heap)
5. [Trie](#trie)
6. [Union Find (Disjoint Set)](#union-find)
7. [Segment Tree](#segment-tree)
8. [Fenwick Tree](#fenwick-tree)
9. [Sparse Table](#sparse-table)

## Binary Trees

### Overview
Binary trees are hierarchical data structures where each node has at most two children: a left child and a right child. Common operations include insertion, traversal (inorder, preorder, postorder), and height calculation.

### Basic Binary Tree Implementation
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    
    void inorderTraversalHelper(TreeNode* node) {
        if (!node) return;
        inorderTraversalHelper(node->left);
        cout << node->val << " ";
        inorderTraversalHelper(node->right);
    }
    
    int heightHelper(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }
    
public:
    BinaryTree() : root(nullptr) {}
    
    void insert(int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (!current->left) {
                current->left = new TreeNode(val);
                return;
            }
            if (!current->right) {
                current->right = new TreeNode(val);
                return;
            }
            
            q.push(current->left);
            q.push(current->right);
        }
    }
    
    void inorderTraversal() {
        inorderTraversalHelper(root);
        cout << endl;
    }
    
    int height() {
        return heightHelper(root);
    }
};
```

## Binary Search Trees

### Overview
Binary Search Trees (BSTs) are binary trees where each node follows the property: left child < parent < right child. This structure supports efficient insertion, deletion, and lookup operations.

### Self-Balancing BST Implementation
```cpp
class BST {
private:
    struct Node {
        int val;
        Node *left, *right;
        int height;
        
        Node(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
    };
    
    Node* root;
    
    int height(Node* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return y;
    }
    
    Node* insertHelper(Node* node, int val) {
        if (!node) return new Node(val);
        
        if (val < node->val)
            node->left = insertHelper(node->left, val);
        else if (val > node->val)
            node->right = insertHelper(node->right, val);
        else
            return node;
            
        node->height = 1 + max(height(node->left), height(node->right));
        
        int balance = getBalance(node);
        
        if (balance > 1 && val < node->left->val)
            return rightRotate(node);
        
        if (balance < -1 && val > node->right->val)
            return leftRotate(node);
        
        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
public:
    BST() : root(nullptr) {}
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
};
```

## Trie (Prefix Tree)

### Overview
A Trie is a tree-like data structure used for storing strings efficiently. It is widely used in autocomplete systems and dictionary-based problems.

### Trie Implementation for Strings
```cpp
class Trie {
private:
    struct TrieNode {
        array<TrieNode*, 26> children;
        bool isEndOfWord;
        
        TrieNode() : isEndOfWord(false) {
            fill(children.begin(), children.end(), nullptr);
        }
    };
    
    TrieNode* root;
    
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    bool search(const string& word) {
        TrieNode* node = findNode(word);
        return node && node->isEndOfWord;
    }
    
    bool startsWith(const string& prefix) {
        return findNode(prefix) != nullptr;
    }
    
private:
    TrieNode* findNode(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                return nullptr;
            }
            current = current->children[index];
        }
        return current;
    }
};
```

## Union Find (Disjoint Set)

### Union Find with Path Compression and Union by Rank
```cpp
class UnionFind {
private:
    vector<int> parent, rank;
    int count;  // Number of distinct sets
    
public:
    UnionFind(int n) : count(n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
            count--;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int getCount() const {
        return count;
    }
};
```

## Segment Tree

### Segment Tree with Lazy Propagation
```cpp
class SegmentTree {
private:
    vector<int> tree, lazy;
    int n;
    
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void updateRangeHelper(int node, int start, int end, 
                          int l, int r, int val) {
        propagate(node, start, end);
        
        if (start > end || start > r || end < l) return;
        
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }
        
        int mid = (start + end) / 2;
        updateRangeHelper(2 * node + 1, start, mid, l, r, val);
        updateRangeHelper(2 * node + 2, mid + 1, end, l, r, val);
        
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    
    int queryRangeHelper(int node, int start, int end, 
                        int l, int r) {
        if (start > end || start > r || end < l) return 0;
        
        propagate(node, start, end);
        
        if (start >= l && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return queryRangeHelper(2 * node + 1, start, mid, l, r) +
               queryRangeHelper(2 * node + 2, mid + 1, end, l, r);
    }
    
public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }
    
    void updateRange(int l, int r, int val) {
        updateRangeHelper(0, 0, n - 1, l, r, val);
    }
    
    int queryRange(int l, int r) {
        return queryRangeHelper(0, 0, n - 1, l, r);
    }
};
```

## Sparse Table

### Sparse Table for Range Minimum Queries
```cpp
class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> log;
    int n;
    
public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        
        // Precompute logs
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i/2] + 1;
        }
        
        // Build sparse table
        int k = log[n];
        st.resize(n, vector<int>(k + 1));
        
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j-1], 
                              st[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    // Query for minimum in range [l, r]
    int query(int l, int r) {
        int j = log[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
```

## Complexity Analysis

### Time Complexities:

1. **Binary Tree:**
   - Insertion: O(n) in worst case
   - Search: O(n) in worst case
   - Traversal: O(n)

2. **Binary Search Tree:**
   - Balanced Insert: O(log n)
   - Balanced Search: O(log n)
   - Rotation: O(1)

3. **Trie:**
   - Insert: O(m) where m is string length
   - Search: O(m) where m is string length
   - Space: O(ALPHABET_SIZE * m * n) where n is number of strings

4. **Union Find:**
   - Find: O(α(n)) ≈ O(1) amortized
   - Union: O(α(n)) ≈ O(1) amortized
   - Space: O(n)

5. **Segment Tree:**
   - Build: O(n)
   - Update: O(log n)
   - Query: O(log n)
   - Space: O(n)

6. **Sparse Table:**
   - Build: O(n log n)
   - Query: O(1)
   - Space: O(n log n)

### Common Applications:

1. **Binary Trees:**
   - File system organization
   - Expression evaluation
   - Decision trees

2. **BST:**
   - Dynamic sorted data
   - Priority queues
   - Symbol tables

3. **Trie:**
   - Autocomplete
   - Spell checkers
   - IP routing tables

4. **Union Find:**
   - Detecting cycles in graphs
   - Network connectivity
   - Image segmentation

5. **Segment Tree:**
   - Range queries
   - Range updates
   - Computational geometry

6. **Sparse Table:**
   - Range minimum/maximum queries
   - Lowest common ancestor
   - String matching

### Implementation Tips:

1. **Memory Management:**
   - Use smart pointers for tree nodes
   - Consider memory pools for frequent allocations
   - Clean up resources in destructors

2. **Performance Optimization:**
   - Use path compression in Union Find
   - Implement lazy propagation in Segment Trees
   - Use bit manipulation where applicable

3. **Error Handling:**
   - Handle edge cases (empty structures)
   - Validate input parameters
   - Implement proper error reporting

```cpp
// Example of smart pointer usage with BST
class ModernBST {
    struct Node {
        int val;
        shared_ptr<Node> left, right;
        Node(int x) : val(x) {}
    };
    
    shared_ptr<Node> root;
    
public:
    // Implementation using smart pointers
};
```

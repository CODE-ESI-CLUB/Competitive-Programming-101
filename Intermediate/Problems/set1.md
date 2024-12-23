Competitive programming is about solving challenges systematically. Below is a collection of intermediate-level problems categorized by topics. Each chapter focuses on a specific type of problem or algorithm, with well-structured problem statements and examples to guide you.

---

## **Table of Contents**
1. [Array & Matrix Manipulation](#array-and-matrix-manipulation)
2. [Sorting and Searching](#sorting-and-searching)
3. [Dynamic Programming](#dynamic-programming)
4. [Graph Problems](#graph-problems)
5. [Bit Manipulation](#bit-manipulation)
6. [Divide and Conquer](#divide-and-conquer)
7. [Greedy Algorithms](#greedy-algorithms)
8. [Tree and Graph Data Structures](#tree-and-graph-data-structures)
9. [Sliding Window and Two Pointers](#sliding-window-and-two-pointers)
10. [String Algorithms](#string-algorithms)
11. [Miscellaneous Problems](#miscellaneous-problems)

---

## **1. Array & Matrix Manipulation**

### **Problem 1: Maximum Subarray Sum (Kadane’s Algorithm)**
- **Statement**: Given an array of integers, find the maximum sum of any contiguous subarray.
- **Input**: A single array of size `n` with elements `a[i]`.
- **Output**: Maximum sum of contiguous subarray.
- **Example**:
  - Input: `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`
  - Output: `6`
- **Test Cases**:
  ```
  Input: [1, 2, 3, -2, 5]
  Output: 9

  Input: [-1, -2, -3, -4]
  Output: -1
  ```

---

### **Problem 2: Spiral Matrix Traversal**
- **Statement**: Print the elements of a matrix in a spiral order starting from the top-left corner.
- **Input**: A 2D matrix of dimensions `m x n`.
- **Output**: The elements in spiral order.
- **Example**:
  ```
  Input: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
  ```
- **Test Cases**:
  ```
  Input: [[1, 2], [3, 4]]
  Output: [1, 2, 4, 3]

  Input: [[1]]
  Output: [1]
  ```

---

## **2. Sorting and Searching**

### **Problem 3: Find the Median of Two Sorted Arrays**
- **Statement**: Find the median of two sorted arrays in O(log(min(n, m))) time.
- **Input**: Two sorted arrays of size `n` and `m`.
- **Output**: Median of the merged array.
- **Example**:
  ```
  Input: [1, 3], [2]
  Output: 2.0
  ```
- **Test Cases**:
  ```
  Input: [1, 2], [3, 4]
  Output: 2.5

  Input: [0, 0], [0, 0]
  Output: 0.0
  ```

---

## **3. Dynamic Programming**

### **Problem 4: Longest Increasing Subsequence (LIS)**
- **Statement**: Find the length of the longest subsequence where all elements are in increasing order.
- **Input**: An array of integers.
- **Output**: Length of the longest increasing subsequence.
- **Example**:
  ```
  Input: [10, 9, 2, 5, 3, 7, 101, 18]
  Output: 4
  ```
- **Test Cases**:
  ```
  Input: [3, 10, 2, 1, 20]
  Output: 3

  Input: [50, 3, 10, 7, 40, 80]
  Output: 4
  ```

### **Problem 5: 0/1 Knapsack Problem**
- **Statement**: Solve the classic knapsack problem using dynamic programming.
- **Input**: A set of weights and corresponding values, and a total weight limit.
- **Output**: Maximum value that can be achieved without exceeding the weight limit.
- **Example**:
  ```
  Input: Weights = [1, 3, 4, 5], Values = [1, 4, 5, 7], Capacity = 7
  Output: 9
  ```
- **Test Cases**:
  ```
  Input: Weights = [1, 2, 3], Values = [6, 10, 12], Capacity = 5
  Output: 22

  Input: Weights = [4, 5, 1], Values = [1, 2, 3], Capacity = 4
  Output: 3
  ```

---

## **4. Graph Problems**

### **Problem 6: Shortest Path in Weighted Graph**
- **Statement**: Given a graph, find the shortest path from the source to all vertices using Dijkstra's algorithm.
- **Input**: A weighted graph represented as adjacency list or matrix and the source vertex.
- **Output**: Shortest path to all vertices from the source.
- **Test Cases**:
  ```
  Input: Graph = {(0, 1, 4), (0, 2, 1), (2, 1, 2), (1, 3, 1)}, Source = 0
  Output: [0, 3, 1, 4]

  Input: Graph = {(0, 1, 10), (1, 2, 5), (2, 3, 1), (3, 0, 2)}, Source = 0
  Output: [0, 10, 15, 16]
  ```

### **Problem 7: Detect Cycle in Undirected Graph**
- **Statement**: Use Union-Find or BFS/DFS to detect cycles in an undirected graph.
- **Input**: A graph represented as adjacency list.
- **Output**: Boolean indicating presence of a cycle.
- **Test Cases**:
  ```
  Input: Graph = {(0, 1), (1, 2), (2, 0)}
  Output: True

  Input: Graph = {(0, 1), (1, 2)}
  Output: False
  ```

---

## **5. Bit Manipulation**

### **Problem 8: Find the Missing Number**
- **Statement**: Use XOR properties to find the missing number in an array of size `n` containing elements from `1 to n`.
- **Input**: An array of integers containing `n - 1` elements.
- **Output**: The missing number.
- **Test Cases**:
  ```
  Input: [1, 2, 4, 6, 3, 7, 8]
  Output: 5

  Input: [1, 3, 4, 5, 6]
  Output: 2
  ```

### **Problem 9: Count Set Bits**
- **Statement**: Given a number, find the total number of 1s in its binary representation.
- **Input**: A single integer `n`.
- **Output**: Total number of set bits.
- **Test Cases**:
  ```
  Input: 5
  Output: 2

  Input: 15
  Output: 4
  ```

---

## **6. Divide and Conquer**

### **Problem 10: Closest Pair of Points**
- **Statement**: Find the smallest distance between two points in a set using a divide-and-conquer approach.
- **Input**: A list of points on a 2D plane.
- **Output**: The smallest distance between any two points.
- **Test Cases**:
  ```
  Input: [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
  Output: 1.414

  Input: [(0, 0), (1, 1), (3, 3)]
  Output: 1.414
  ```

---

## **7. Greedy Algorithms**

### **Problem 11: Activity Selection Problem**
- **Statement**: Given `n` activities with start and end times, select the maximum number of activities that can be performed without overlapping.
- **Input**: Two arrays `start[]` and `end[]` of size `n`.
- **Output**: Maximum number of non-overlapping activities.
- **Example**:
  ```
  Input: start = [1, 3, 0, 5, 8, 5], end = [2, 4, 6, 7, 9, 9]
  Output: 4
  ```
- **Test Cases**:
  ```
  Input: start = [10, 12, 20], end = [20, 25, 30]
  Output: 2

  Input: start = [1, 2], end = [3, 4]
  Output: 2
  ```

---

### **Problem 12: Huffman Encoding**
- **Statement**: Given a string with characters and frequencies, generate its Huffman encoding using a greedy approach.
- **Input**: A string `s` and an array of frequencies `f[]`.
- **Output**: Encoded binary strings for all characters.
- **Example**:
  ```
  Input: s = "aabcc", f = [5, 9, 12, 13]
  Output: a:00, b:01, c:1
  ```
- **Test Cases**:
  ```
  Input: s = "abc", f = [2, 3, 5]
  Output: a:00, b:01, c:1

  Input: s = "aaa", f = [1, 1, 1]
  Output: a:0, b:10, c:11
  ```

---

## **8. Tree and Graph Data Structures**

### **Problem 13: Lowest Common Ancestor**
- **Statement**: Find the lowest common ancestor (LCA) of two nodes in a binary tree.
- **Input**: A binary tree and two nodes `p` and `q`.
- **Output**: The lowest common ancestor node.
- **Example**:
  ```
  Input: Tree = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
  Output: 3
  ```
- **Test Cases**:
  ```
  Input: Tree = [2, 1], p = 1, q = 2
  Output: 2

  Input: Tree = [3, 5, 1, 6], p = 6, q = 5
  Output: 5
  ```

---

### **Problem 14: Detect Cycle in Directed Graph**
- **Statement**: Use DFS or Kahn’s algorithm to detect a cycle in a directed graph.
- **Input**: A graph represented as an adjacency list.
- **Output**: Boolean indicating presence of a cycle.
- **Example**:
  ```
  Input: Graph = {1 -> 2 -> 3 -> 1}
  Output: True
  ```
- **Test Cases**:
  ```
  Input: Graph = {1 -> 2, 2 -> 3, 3 -> 4}
  Output: False

  Input: Graph = {1 -> 2, 2 -> 3, 3 -> 1}
  Output: True
  ```

---

## **9. Sliding Window and Two Pointers**

### **Problem 15: Longest Substring Without Repeating Characters**
- **Statement**: Find the length of the longest substring without repeating characters in a string.
- **Input**: A string `s`.
- **Output**: Length of the longest substring.
- **Example**:
  ```
  Input: s = "abcabcbb"
  Output: 3
  ```
- **Test Cases**:
  ```
  Input: s = "bbbbb"
  Output: 1

  Input: s = "pwwkew"
  Output: 3
  ```

---

### **Problem 16: Minimum Window Substring**
- **Statement**: Find the smallest substring of `s` containing all characters of string `t`.
- **Input**: Strings `s` and `t`.
- **Output**: Smallest window substring.
- **Example**:
  ```
  Input: s = "ADOBECODEBANC", t = "ABC"
  Output: "BANC"
  ```
- **Test Cases**:
  ```
  Input: s = "a", t = "a"
  Output: "a"

  Input: s = "a", t = "aa"
  Output: ""
  ```

---

## **10. String Algorithms**

### **Problem 17: Longest Palindromic Substring**
- **Statement**: Find the longest substring in a given string that is a palindrome.
- **Input**: A string `s`.
- **Output**: Longest palindromic substring.
- **Example**:
  ```
  Input: s = "babad"
  Output: "bab" or "aba"
  ```
- **Test Cases**:
  ```
  Input: s = "cbbd"
  Output: "bb"

  Input: s = "a"
  Output: "a"
  ```

---

### **Problem 18: KMP String Matching Algorithm**
- **Statement**: Use the Knuth-Morris-Pratt algorithm to find if a pattern exists in a string.
- **Input**: Strings `text` and `pattern`.
- **Output**: Start index of the first occurrence (or -1 if not found).
- **Example**:
  ```
  Input: text = "abxabcabcaby", pattern = "abcaby"
  Output: 6
  ```
- **Test Cases**:
  ```
  Input: text = "aaaaa", pattern = "bba"
  Output: -1

  Input: text = "aabaac", pattern = "baac"
  Output: 2
  ```

---

## **11. Miscellaneous Problems**

### **Problem 19: Sudoku Solver**
- **Statement**: Solve a partially filled 9x9 Sudoku grid.
- **Input**: A 2D array representing a Sudoku board.
- **Output**: A completed valid Sudoku grid.
- **Example**:
  ```
  Input: board = [[5,3,'.','.',7,'.','.','.','.'],...] 
  Output: [[5,3,4,6,7,8,9,1,2], ...]
  ```

---

### **Problem 20: Minimum Cost to Connect Points**
- **Statement**: Use Prim's or Kruskal's algorithm to find the minimum cost to connect all points in a 2D space.
- **Input**: Array of points with `x, y` coordinates.
- **Output**: Minimum connection cost.
- **Example**:
  ```
  Input: [[0,0],[2,2],[3,10],[5,2],[7,0]]
  Output: 20
  ```

---


### Problem 1: Maximum Subarray Sum (Kadane’s Algorithm)  
**Statement**: Given an array of integers, find the sum of the contiguous subarray that has the maximum sum.  

**Input**:  
- A single integer `N` (1 ≤ N ≤ 10^5), followed by `N` integers (can include negative values).  
**Output**: The maximum subarray sum.  

**Example**:  
Input:  
```
8  
-2 1 -3 4 -1 2 1 -5 4  
```  
Output: `6`  

---

### Problem 2: Longest Subarray with Sum X  
**Statement**: Find the length of the longest subarray in a given array whose elements sum to `X`.  

**Input**:  
- An integer `N` (1 ≤ N ≤ 10^5), followed by `N` integers.  
- An integer `X`.  
**Output**: The length of the longest subarray with sum `X`.  

**Example**:  
Input:  
```
6  
1 2 3 -2 5 1  
5  
```  
Output: `2`  

---

### Problem 3: Find Cycle in a Directed Graph  
**Statement**: Given a directed graph with `N` vertices and `M` edges, determine if there is a cycle.  

**Input**:  
- Two integers `N` and `M` (1 ≤ N, M ≤ 10^4).  
- Followed by `M` pairs of integers representing directed edges.  

**Output**:  
`"YES"` if a cycle exists, otherwise `"NO"`.  

**Example**:  
Input:  
```
4 4  
1 2  
2 3  
3 4  
4 2  
```  
Output: `"YES"`  

---

### Problem 4: Minimum Spanning Tree (Kruskal or Prim’s Algorithm)  
**Statement**: Given an undirected weighted graph with `N` vertices and `M` edges, find the weight of the minimum spanning tree (MST).  

**Input**:  
- Two integers `N` and `M` (1 ≤ N, M ≤ 10^5).  
- Followed by `M` triplets: `u v w` where `u` and `v` are vertices, and `w` is the weight of the edge.  

**Output**: The weight of the MST.  

**Example**:  
Input:  
```
4 5  
1 2 3  
2 3 1  
3 4 4  
4 1 2  
1 3 5  
```  
Output: `7`  

---

### Problem 5: Matrix Rotation  
**Statement**: Rotate a given `N x N` matrix 90 degrees clockwise.  

**Input**:  
A single integer `N` (1 ≤ N ≤ 500), followed by an `N x N` matrix of integers.  
**Output**: The rotated matrix.  

**Example**:  
Input:  
```
3  
1 2 3  
4 5 6  
7 8 9  
```  
Output:  
```
7 4 1  
8 5 2  
9 6 3  
```  

---

### Problem 6: Subset Sum  
**Statement**: Determine if a subset of the given array sums up to a target `S`.  

**Input**:  
- An integer `N` (1 ≤ N ≤ 100), followed by `N` integers.  
- An integer `S`.  

**Output**: `"YES"` if such a subset exists, otherwise `"NO"`.  

**Example**:  
Input:  
```
5  
1 2 3 7 8  
10  
```  
Output: `"YES"`  

---

### Problem 7: Shortest Path in Weighted Graph (Dijkstra’s Algorithm)  
**Statement**: Given a weighted directed graph with `N` vertices and `M` edges, find the shortest path from a source vertex `S` to all other vertices.  

**Input**:  
- Two integers `N` and `M` (1 ≤ N, M ≤ 10^5).  
- An integer `S` (1 ≤ S ≤ N).  
- Followed by `M` triplets: `u v w`, where `u` and `v` are vertices, and `w` is the weight of the edge.  

**Output**: A list of shortest distances from the source vertex `S` to all other vertices. If a vertex is unreachable, output `-1`.  

**Example**:  
Input:  
```
4 4 1  
1 2 4  
1 3 2  
3 2 1  
2 4 7  
```  
Output: `0 3 2 10`  

---

### Problem 8: Binary Search on Answer (Aggressive Cows Problem)  
**Statement**: Place `C` cows in `N` stalls such that the minimum distance between any two cows is maximized.  

**Input**:  
- Two integers `N` and `C` (2 ≤ C ≤ N ≤ 10^5).  
- Followed by `N` integers representing stall positions.  

**Output**: The maximum minimum distance.  

**Example**:  
Input:  
```
5 3  
1 2 8 4 9  
```  
Output: `3`  

---

### Problem 9: Kth Smallest Element in a Sorted Matrix  
**Statement**: Given a `N x N` matrix where each row and column are sorted in increasing order, find the `K`-th smallest element.  

**Input**:  
- Two integers `N` (1 ≤ N ≤ 500) and `K` (1 ≤ K ≤ N^2).  
- An `N x N` matrix of integers.  

**Output**: The `K`-th smallest element.  

**Example**:  
Input:  
```
3 5  
1 5 9  
10 11 13  
12 13 15  
```  
Output: `11`  

---

### Problem 10: Longest Common Subsequence  
**Statement**: Find the length of the longest common subsequence (LCS) between two strings `A` and `B`.  

**Input**:  
- Two strings `A` and `B` of lengths `N` and `M`, respectively (1 ≤ N, M ≤ 1000).  
**Output**: The length of the LCS.  

**Example**:  
Input:  
```
abcde  
ace  
```  
Output: `3`  

---

### Problem 11: K Closest Points to Origin  
**Statement**: Given `N` points in a 2D plane, find the `K` points closest to the origin `(0, 0)`.  

**Input**:  
- Two integers `N` and `K` (1 ≤ K ≤ N ≤ 10^5).  
- Followed by `N` pairs of integers, each representing a point `(x, y)`.  

**Output**: The `K` closest points in any order.  

**Example**:  
Input:  
```
5 3  
1 3  
-2 2  
5 8  
0 1  
-1 -1  
```  
Output:  
```
-2 2  
0 1  
-1 -1  
```  

---

### Problem 12: Trap Rainwater  
**Statement**: Given an array of heights, compute the amount of rainwater trapped between the heights.  

**Input**:  
- A single integer `N` (1 ≤ N ≤ 10^5).  
- Followed by an array of `N` non-negative integers.  

**Output**: The total amount of water trapped.  

**Example**:  
Input:  
```
6  
0 1 0 2 1 0 1 3 2 1 2 1  
```  
Output: `6`  

---

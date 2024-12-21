

### **Beginner/Concepts.md**


# Core Concepts for Beginners

Welcome to the **Core Concepts** guide! This document covers fundamental ideas you need to understand before diving into competitive programming. 

---

## 📖 Table of Contents

1. [Introduction to Competitive Programming](#introduction-to-competitive-programming)
2. [Input and Output](#input-and-output)
3. [Time Complexity](#time-complexity)
4. [Space Complexity](#space-complexity)
5. [Basic Recursion](#basic-recursion)
6. [Greedy Approach](#greedy-approach)
7. [Basic Sorting Algorithms](#basic-sorting-algorithms)
8. [Common Mistakes to Avoid](#common-mistakes-to-avoid)

---

## 🔰 Introduction to Competitive Programming

Competitive programming involves solving well-defined algorithmic problems within a specified time frame. It requires:
- Analytical thinking
- Proficiency in at least one programming language (e.g., C++, Python)
- Knowledge of algorithms and data structures

**Goal**: Write efficient, correct, and elegant code.

---

## 🖊️ Input and Output

### Input:
Handling input efficiently is crucial in contests. Most problems follow a standard format, such as:
- Single-line input
- Multi-line input
- Array or matrix input

#### Examples:
**Python**:
```python
n = int(input())  # Single integer
arr = list(map(int, input().split()))  # List of integers
```

**C++**:
```cpp
int n;
cin >> n;  // Single integer
vector<int> arr(n);
for (int &x : arr) cin >> x;  // Array input
```

---

### Output:
Ensure your output format matches the problem's requirements.
- Use formatted strings where necessary.
- Avoid unnecessary whitespaces or extra lines.

---

## ⏳ Time Complexity

Time complexity measures how an algorithm's runtime scales with input size `n`. 

### Common Complexities:
| Complexity    | Example Algorithm           | Input Size (`n`)   |
|---------------|-----------------------------|--------------------|
| **O(1)**      | Accessing an array element  | Constant           |
| **O(log n)**  | Binary Search               | 10⁷ - 10⁸          |
| **O(n)**      | Linear Search               | 10⁶ - 10⁷          |
| **O(n log n)**| Merge Sort                  | 10⁵ - 10⁶          |
| **O(n²)**     | Bubble Sort                 | ~10⁴               |

**Tips**:
- Aim for `O(log n)`, `O(n)`, or `O(n log n)` solutions in contests.
- Avoid nested loops for large inputs unless optimized.

---

## 🧮 Space Complexity

Space complexity measures memory usage. Keep in mind:
1. Use efficient data structures like arrays or maps.
2. Avoid storing unnecessary intermediate results.
3. Reuse variables wherever possible.

---

## 🔂 Basic Recursion

Recursion is a technique where a function calls itself. Ensure:
- You define a **base case** to avoid infinite recursion.
- Recursion depth is manageable for the given problem constraints.

**Example** (Factorial):
**Python**:
```python
def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n-1)
```

**C++**:
```cpp
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}
```

---

## 💡 Greedy Approach

Greedy algorithms build up a solution piece by piece, always choosing the next piece with the most immediate benefit.

**Example Problem**: Coin Change  
Given coins of denominations `{1, 5, 10, 25}`, minimize the number of coins to make a sum `S`.

---

## 🔀 Basic Sorting Algorithms

1. **Bubble Sort** - Repeatedly swap adjacent elements if they are in the wrong order.
2. **Selection Sort** - Find the minimum element and place it at the start.
3. **Insertion Sort** - Build the sorted array one element at a time.

**Key Takeaway**: Prefer **Merge Sort** or **Quick Sort** in competitive programming for larger inputs.

---

## ⚠️ Common Mistakes to Avoid

1. **Off-by-One Errors**:
   - Carefully handle 0-based vs. 1-based indexing.

2. **Unoptimized Code**:
   - Avoid unnecessary loops or operations.

3. **Misreading the Problem**:
   - Read the problem statement and constraints thoroughly.

4. **Incorrect Output Format**:
   - Match the output format exactly as described in the problem.

---

Mastering these concepts will help you build a strong foundation in competitive programming. Dive into the **[Problems folder](./Problems/)** to practice these ideas!

---
Happy coding! 🚀
``` 

Let me know if you’d like more sections or further customizations!

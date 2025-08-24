# Troubleshooting Guide

This guide helps you resolve common issues you might encounter while using this repository or practicing competitive programming.

---

## 🔧 Common Technical Issues

### 1. Compilation Errors

**Problem:** Your C++ code doesn't compile
**Solutions:**
```bash
# Ensure you're using the correct compiler flags
g++ -o solution solution.cpp -std=c++17

# For debugging, add debug flag
g++ -o solution solution.cpp -std=c++17 -g -DDEBUG

# For competitive programming, use optimization
g++ -o solution solution.cpp -std=c++17 -O2
```

**Common C++ compilation issues:**
- Missing `#include` statements
- Forgetting `using namespace std;` or prefixing with `std::`
- Using C++17/20 features with older compiler versions

### 2. Runtime Errors

**Problem:** Code compiles but crashes during execution

**Common causes and solutions:**
- **Array out of bounds:** Use `vector` instead of arrays, or carefully check array bounds
- **Division by zero:** Always check for zero before division
- **Infinite recursion:** Add proper base cases to recursive functions
- **Integer overflow:** Use `long long` for large numbers

```cpp
// Bad
int factorial(int n) {
    return n * factorial(n-1);  // No base case!
}

// Good  
long long factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return (long long)n * factorial(n-1);
}
```

### 3. Time Limit Exceeded (TLE)

**Problem:** Solution is correct but too slow

**Solutions:**
1. **Optimize algorithm complexity**
   ```cpp
   // O(n²) - Slow
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           // operation
       }
   }
   
   // O(n log n) - Better
   sort(arr.begin(), arr.end());
   ```

2. **Use faster I/O**
   ```cpp
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ```

3. **Choose better data structures**
   - Use `unordered_map` instead of `map` when order doesn't matter
   - Use `vector` instead of `list` for random access
   - Use `deque` for fast insertion at both ends

### 4. Wrong Answer (WA)

**Problem:** Logic error in your solution

**Debugging steps:**
1. **Read the problem statement again carefully**
2. **Check edge cases:**
   - Empty input
   - Single element
   - All elements same
   - Maximum/minimum constraints

3. **Add debug prints:**
   ```cpp
   #ifdef DEBUG
   #define debug(x) cout << #x << " = " << x << endl
   #else
   #define debug(x)
   #endif
   ```

4. **Test with sample inputs manually**

### 5. Memory Limit Exceeded (MLE)

**Problem:** Using too much memory

**Solutions:**
- Use appropriate data types (`int` vs `long long`)
- Avoid creating unnecessary large arrays
- Consider space-optimized algorithms
- Use iterative instead of recursive approaches when possible

---

## 🐍 Python-Specific Issues

### 1. Import Errors
```python
# Common imports for competitive programming
import sys
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop
import bisect
import math
```

### 2. Input/Output Issues
```python
# Fast input
input = sys.stdin.readline

# Multiple test cases
t = int(input())
for _ in range(t):
    # solve each test case
    pass

# Reading arrays
arr = list(map(int, input().split()))
```

### 3. Recursion Limit
```python
# Increase recursion limit for deep recursive calls
sys.setrecursionlimit(10**6)
```

---

## 🌐 Platform-Specific Issues

### Codeforces
- **Pretest vs System Test:** Solutions that pass pretests may fail system tests
- **Interactive Problems:** Use `sys.stdout.flush()` after each query in Python
- **Polygon:** Practice on Polygon if available before contests

### LeetCode
- **Return vs Print:** Return the answer, don't print it
- **Edge Cases:** Pay attention to constraints (empty arrays, single elements)
- **Time Complexity:** Usually need O(n) or O(n log n) solutions

### HackerRank
- **Exact Output Format:** Follow the exact output format specified
- **Custom Input:** May need to handle custom input reading

---

## 🔍 Debugging Strategies

### 1. Systematic Debugging
```cpp
// Add assertions to check your assumptions
assert(n > 0);
assert(i < n);

// Use debug macros
#ifdef DEBUG
    cout << "Debug: i = " << i << ", arr[i] = " << arr[i] << endl;
#endif
```

### 2. Test Case Generation
```cpp
// Generate random test cases for stress testing
#include <random>
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);

for(int test = 0; test < 1000; test++) {
    int n = dis(gen);
    // Generate test case and compare with brute force
}
```

### 3. Binary Search Debugging
When solution partially works:
```cpp
// Binary search on the test cases to find the failing case
// Comment out half of your code to isolate the bug
```

---

## 📚 Learning Resources for Common Problems

### Algorithm Design Issues
- [CP Algorithms](https://cp-algorithms.com/)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)

### Implementation Issues
- [Competitive Programming 3](http://cpbook.net/)
- [USACO Guide](https://usaco.guide/)

### Contest Strategy
- [Codeforces Catalog](https://codeforces.com/catalog)
- Practice editorials after contests

---

## 🆘 Getting Help

### 1. Community Resources
- [Codeforces Blogs](https://codeforces.com/blog/entry)
- [Reddit r/CompetitiveProgramming](https://www.reddit.com/r/CompetitiveProgramming/)
- [Stack Overflow](https://stackoverflow.com/) for technical issues

### 2. Repository Support
- Open an [Issue](https://github.com/CODE-ESI-CLUB/Competitive-Programming-101/issues) using our template
- Join the [Discussions](https://github.com/CODE-ESI-CLUB/Competitive-Programming-101/discussions)
- Contact maintainers: [code@esi.ac.ma]

### 3. What to Include When Asking for Help
- **Problem statement** or link
- **Your code** (formatted properly)
- **Expected vs actual behavior**
- **What you've already tried**
- **Specific error messages**

---

## ⚡ Performance Tips

### 1. Code Organization
```cpp
// Template for faster coding
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second
#define sz(x) (int)x.size()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Your code here
    
    return 0;
}
```

### 2. Common Patterns
```cpp
// Precompute when possible
vector<ll> fact(n+1);
fact[0] = 1;
for(int i = 1; i <= n; i++) {
    fact[i] = fact[i-1] * i;
}

// Use appropriate containers
unordered_set<int> for O(1) lookup
vector<int> for indexed access
priority_queue<int> for heap operations
```

---

**Remember:** The best way to get better at debugging is practice. Don't get discouraged by errors – they're part of the learning process! 🚀
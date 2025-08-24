# Beginner Problem Set 3: Control Structures & Basic Algorithms

This set focuses on loops, conditionals, and basic algorithmic thinking.

---

## Problem 1: Even Numbers in Range
**Statement**: Print all even numbers between 1 and N (inclusive).

**Input**: A single integer N (1 ≤ N ≤ 1000).

**Output**: All even numbers from 1 to N, each on a new line.

**Example**:
```
Input: 10
Output: 
2
4
6
8
10
```

**Solution Hint**: Use a loop and check if i % 2 == 0.

---

## Problem 2: Pattern Printing
**Statement**: Print a right triangle pattern using stars.

**Input**: A single integer N (1 ≤ N ≤ 20).

**Output**: N lines where line i has i stars.

**Example**:
```
Input: 4
Output:
*
**
***
****
```

---

## Problem 3: Prime Number Check
**Statement**: Determine if a given number is prime.

**Input**: A single integer N (1 ≤ N ≤ 10^6).

**Output**: "YES" if N is prime, "NO" otherwise.

**Example**:
```
Input: 17
Output: YES

Input: 15  
Output: NO
```

**Solution Hint**: Check divisibility from 2 to √N.

---

## Problem 4: GCD (Greatest Common Divisor)
**Statement**: Find the GCD of two numbers using Euclidean algorithm.

**Input**: Two integers A and B (1 ≤ A, B ≤ 10^9).

**Output**: GCD of A and B.

**Example**:
```
Input: 48 18
Output: 6
```

**Algorithm**: 
```
gcd(a, 0) = a
gcd(a, b) = gcd(b, a % b)
```

---

## Problem 5: Array Rotation
**Statement**: Rotate an array to the right by K positions.

**Input**: 
- Integer N (1 ≤ N ≤ 10^5)
- N space-separated integers (array elements)
- Integer K (0 ≤ K ≤ N)

**Output**: The rotated array.

**Example**:
```
Input:
5
1 2 3 4 5
2
Output: 4 5 1 2 3
```

**Solution Hint**: K rotations right = (N-K) rotations left.

---

## Problem 6: Count Vowels and Consonants
**Statement**: Count vowels and consonants in a string.

**Input**: A string S containing only lowercase letters (1 ≤ |S| ≤ 1000).

**Output**: Two integers: number of vowels and number of consonants.

**Example**:
```
Input: programming
Output: 3 8
```

**Note**: Vowels are a, e, i, o, u.

---

## Problem 7: Second Largest Element
**Statement**: Find the second largest element in an array.

**Input**:
- Integer N (2 ≤ N ≤ 10^5)
- N space-separated distinct integers

**Output**: The second largest element.

**Example**:
```
Input:
5
5 3 8 1 9
Output: 8
```

**Solution Hint**: Keep track of largest and second largest while iterating.

---

## Problem 8: Simple Calculator
**Statement**: Implement a calculator that performs basic operations.

**Input**: Two numbers A, B and an operator (+, -, *, /).

**Output**: Result of the operation.

**Example**:
```
Input: 10 5 +
Output: 15

Input: 12 4 /
Output: 3
```

**Constraints**: Division by zero should output "ERROR".

---

## Problem 9: Perfect Number
**Statement**: Check if a number is perfect (sum of its proper divisors equals the number).

**Input**: A positive integer N (1 ≤ N ≤ 10^6).

**Output**: "YES" if N is perfect, "NO" otherwise.

**Example**:
```
Input: 28
Output: YES
```

**Explanation**: 28 = 1 + 2 + 4 + 7 + 14 (proper divisors of 28).

---

## Problem 10: Number System Conversion
**Statement**: Convert a decimal number to binary representation.

**Input**: A non-negative integer N (0 ≤ N ≤ 10^9).

**Output**: Binary representation of N.

**Example**:
```
Input: 10
Output: 1010

Input: 0
Output: 0
```

---

## Problem 11: Leap Year Check
**Statement**: Determine if a given year is a leap year.

**Input**: A year Y (1 ≤ Y ≤ 3000).

**Output**: "YES" if it's a leap year, "NO" otherwise.

**Example**:
```
Input: 2020
Output: YES

Input: 1900
Output: NO
```

**Rules**: 
- Divisible by 4 AND
- If divisible by 100, must also be divisible by 400

---

## Problem 12: Armstrong Number
**Statement**: Check if a number is an Armstrong number (sum of cubes of digits equals the number).

**Input**: A positive integer N (1 ≤ N ≤ 10^6).

**Output**: "YES" if N is Armstrong, "NO" otherwise.

**Example**:
```
Input: 153
Output: YES
```

**Explanation**: 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153

---

## Tips for Solving These Problems:

1. **Read Carefully**: Understand input/output format
2. **Plan First**: Write pseudocode before coding
3. **Test Edge Cases**: Try minimum/maximum values
4. **Use Efficient Methods**: Think about time complexity
5. **Debug Step by Step**: Use print statements to trace execution

## Sample Solution Template (C++):

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Read input
    int n;
    cin >> n;
    
    // Process
    // ... your logic here ...
    
    // Output result
    cout << result << endl;
    
    return 0;
}
```

## Sample Solution Template (Python):

```python
# Read input
n = int(input())

# Process
# ... your logic here ...

# Output result
print(result)
```

---

**Practice these problems to strengthen your foundation in competitive programming! 🚀**
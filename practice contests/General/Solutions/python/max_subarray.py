# Sample Solution: General Contest Problem
# Problem: Find the maximum subarray sum (Kadane's Algorithm)

def kadane(arr):
    max_so_far = arr[0]
    max_ending_here = arr[0]
    
    for i in range(1, len(arr)):
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    result = kadane(arr)
    print(result)

if __name__ == "__main__":
    main()

"""
Sample Input:
9
-2 1 -3 4 -1 2 1 -5 4

Sample Output:
6

Explanation: Maximum subarray is [4, -1, 2, 1] with sum 6

Time Complexity: O(n)
Space Complexity: O(1)
"""
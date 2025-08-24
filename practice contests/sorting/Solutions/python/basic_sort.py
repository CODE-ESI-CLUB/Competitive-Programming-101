# Sample Solution: Basic Sorting Problem
# Problem: Sort an array of integers

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    # Sort the array
    arr.sort()
    
    # Output sorted array
    print(' '.join(map(str, arr)))

if __name__ == "__main__":
    main()

"""
Sample Input:
5
3 1 4 1 5

Sample Output:
1 1 3 4 5

Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary space
"""
# Sample Solution: Custom Comparison Sorting
# Problem: Sort students by grade (descending), then by name (ascending)

def main():
    n = int(input())
    students = []
    
    for _ in range(n):
        line = input().split()
        name = line[0]
        grade = int(line[1])
        students.append((name, grade))
    
    # Sort using custom key: (-grade, name)
    # Negative grade for descending order, name for ascending order
    students.sort(key=lambda x: (-x[1], x[0]))
    
    # Output sorted students
    for name, grade in students:
        print(f"{name} {grade}")

if __name__ == "__main__":
    main()

"""
Sample Input:
4
Alice 85
Bob 92
Charlie 85
Diana 78

Sample Output:
Bob 92
Alice 85
Charlie 85
Diana 78

Note: Bob has highest grade, then Alice comes before Charlie alphabetically
"""
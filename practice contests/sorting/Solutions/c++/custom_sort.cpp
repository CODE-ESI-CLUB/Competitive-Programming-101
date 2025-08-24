// Sample Solution: Custom Comparison Sorting
// Problem: Sort students by grade (descending), then by name (ascending)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int grade;
};

bool compare(const Student& a, const Student& b) {
    if (a.grade != b.grade) {
        return a.grade > b.grade; // Higher grade first
    }
    return a.name < b.name; // Then alphabetically by name
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].grade;
    }
    
    // Sort using custom comparator
    sort(students.begin(), students.end(), compare);
    
    // Output sorted students
    for (const auto& student : students) {
        cout << student.name << " " << student.grade << endl;
    }
    
    return 0;
}

/*
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
*/
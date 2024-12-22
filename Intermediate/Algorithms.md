# Comprehensive Intermediate Level Algorithms Guide

## Table of Contents
1. [Searching Algorithms](#searching-algorithms)
2. [Sorting Algorithms](#sorting-algorithms)
3. [Dynamic Programming](#dynamic-programming)
4. [Graph Algorithms](#graph-algorithms)
5. [Tree Algorithms](#tree-algorithms)
6. [Number Theory](#number-theory)
7. [Bit Manipulation](#bit-manipulation)
8. [Range Queries](#range-queries)
9. [Game Theory](#game-theory)
10. [Geometry](#geometry)

[Previous sections remain the same up to Number Theory]

## Number Theory

### Extended Greatest Common Divisor (Extended GCD)
```cpp
pair<int, int> extendedGCD(int a, int b) {
    if (b == 0) return {1, 0};
    auto [x1, y1] = extendedGCD(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return {x, y};
}
```

### Modular Multiplicative Inverse
```cpp
int modInverse(int a, int m) {
    auto [x, y] = extendedGCD(a, m);
    return (x % m + m) % m;
}
```

### Prime Factorization
```cpp
vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}
```

### Euler's Totient Function
```cpp
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
```

## Range Queries

### Segment Tree (Range Sum Query)
```cpp
class SegmentTree {
    vector<int> tree;
    int n;
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n-1);
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node+1, start, mid);
        build(arr, 2*node+2, mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node+1, start, mid, idx, val);
        else
            update(2*node+2, mid+1, end, idx, val);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) +
               query(2*node+2, mid+1, end, l, r);
    }
};
```

### Binary Indexed Tree (Fenwick Tree)
```cpp
class FenwickTree {
    vector<int> bit;
    int n;
    
public:
    FenwickTree(int size) {
        n = size;
        bit.resize(n + 1);
    }
    
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += val;
    }
    
    int sum(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    
    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
```

### Sparse Table (Range Minimum Query)
```cpp
class SparseTable {
    vector<vector<int>> st;
    vector<int> log;
    int n;
    
public:
    SparseTable(vector<int>& arr) {
        n = arr.size();
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i/2] + 1;
            
        st.resize(n, vector<int>(log[n] + 1));
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];
            
        for (int j = 1; j <= log[n]; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
    }
    
    int query(int l, int r) {
        int j = log[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
```

## Game Theory

### Nim Game
```cpp
bool canWinNim(vector<int>& piles) {
    int xorSum = 0;
    for (int pile : piles)
        xorSum ^= pile;
    return xorSum != 0;
}
```

### Sprague-Grundy Theorem
```cpp
vector<int> grundy;

int calculateGrundy(int n, vector<int>& moves) {
    if (grundy[n] != -1) return grundy[n];
    set<int> s;
    
    for (int move : moves) {
        if (n >= move)
            s.insert(calculateGrundy(n - move, moves));
    }
    
    int mex = 0;
    while (s.count(mex)) mex++;
    return grundy[n] = mex;
}
```

### Game of Stones
```cpp
bool canWinStones(int n, vector<int>& moves) {
    vector<bool> dp(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        for (int move : moves) {
            if (i >= move && !dp[i - move]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
```

## Geometry

### Point Class
```cpp
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double c) const { return Point(x * c, y * c); }
    double dot(const Point& p) const { return x * p.x + y * p.y; }
    double cross(const Point& p) const { return x * p.y - y * p.x; }
    double norm() const { return sqrt(dot(*this)); }
};
```

### Line Intersection
```cpp
bool lineIntersection(Point p1, Point p2, Point p3, Point p4, Point& intersection) {
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1 * p1.x + b1 * p1.y;
    
    double a2 = p4.y - p3.y;
    double b2 = p3.x - p4.x;
    double c2 = a2 * p3.x + b2 * p3.y;
    
    double det = a1 * b2 - a2 * b1;
    if (abs(det) < 1e-9) return false;
    
    intersection.x = (b2 * c1 - b1 * c2) / det;
    intersection.y = (a1 * c2 - a2 * c1) / det;
    return true;
}
```

### Convex Hull (Graham Scan)
```cpp
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 3) return points;
    
    // Find bottom-most point (and leftmost if tied)
    int bottomPoint = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[bottomPoint].y ||
            (points[i].y == points[bottomPoint].y && 
             points[i].x < points[bottomPoint].x))
            bottomPoint = i;
    }
    swap(points[0], points[bottomPoint]);
    
    // Sort points by polar angle with p0
    Point p0 = points[0];
    sort(points.begin() + 1, points.end(),
        [&p0](const Point& p1, const Point& p2) {
            double val = (p1 - p0).cross(p2 - p0);
            if (abs(val) < 1e-9)
                return (p1 - p0).dot(p1 - p0) < (p2 - p0).dot(p2 - p0);
            return val > 0;
        });
    
    // Build hull
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            Point p1 = hull[hull.size() - 1];
            Point p2 = hull[hull.size() - 2];
            if ((p1 - p2).cross(points[i] - p2) > 0) break;
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    return hull;
}
```

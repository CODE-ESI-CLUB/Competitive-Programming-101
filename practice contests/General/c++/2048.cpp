#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> slideAndMerge(const vector<int>& line) {
    vector<int> result;
    int n = line.size();
    vector<bool> merged(n, false);

    int lastIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (line[i] != 0) {
            if (!result.empty() && result.back() == line[i] && !merged[lastIndex]) {
                result.back() *= 2;    
                merged[lastIndex] = true;  
            } else {
                result.push_back(line[i]);
                lastIndex = result.size() - 1;
            }
        }
    }

    while (result.size() < n) {
        result.push_back(0); 
    }

    return result;
}


void processMove(vector<vector<int>>& grid, int move) {
    if (move == 1 || move == 3) {
       
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (move == 2 || move == 3) {
            reverse(grid[i].begin(), grid[i].end());
        }

        grid[i] = slideAndMerge(grid[i]);

        if (move == 2 || move == 3) {
            reverse(grid[i].begin(), grid[i].end());
        }
    }

    if (move == 1 || move == 3) {
        
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }
}

int main() {
    vector<vector<int>> grid(4, vector<int>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> grid[i][j];
        }
    }

    int move;
    cin >> move;

    processMove(grid, move);

    for (const auto& row : grid) {
        for (int j = 0; j < 4; ++j) {
            cout << row[j] << (j < 3 ? " " : "\n");
        }
    }

    return 0;
}


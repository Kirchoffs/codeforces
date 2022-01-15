#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
        return 0;
    }
    visited[i][j] = true;
    int val = grid[i][j];

    int size = 1;
    for (int k = 0; k < 4; k++) {
        if (val % 2 == 0) {
            size += dfs(grid, visited, i + dirs[k][0], j + dirs[k][1], n, m);
        }
        val /= 2;
    }

    return size;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                res.push_back(dfs(grid, visited, i, j, n, m));
            }
        }
    }

    sort(res.begin(), res.end(), greater<int>());
    for (int re: res) {
        cout << re << " ";
    }
    cout << endl;
}
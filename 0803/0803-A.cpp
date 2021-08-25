#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static bool solve(vector<vector<int>>& matrix, int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (k <= 0) {
                return true;
            }
            if (k == 1) {
                if (i == j) {
                    matrix[i][j] = 1;
                    k--;
                }
            } else {
                if (i == j) {
                    matrix[i][j] = 1;
                    k--;
                } else {
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                    k -= 2;
                }
            }
        }
    }
    return k == 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    if (solve(matrix, n, k)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }
}
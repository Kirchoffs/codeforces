#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    vector<vector<int>> pre(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i][j] = (i > 0 ? pre[i-1][j] : 0) + (j > 0 ? pre[i][j-1] : 0) - (i > 0 && j > 0 ? pre[i-1][j-1] : 0);
            if (i > 0 && matrix[i-1][j] == 'X' && j > 0 && matrix[i][j-1] == 'X') {
                pre[i][j] += 1;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        if (pre[n-1][e] - pre[n-1][s] > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    solve();
}
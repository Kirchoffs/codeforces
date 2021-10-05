#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 400;
int grid[N + 1][N + 1];
int presum[N + 1][N + 1];

int getOnes(int l, int r, int t, int b) {
    return presum[b][r] - presum[b][l-1] - presum[t-1][r] + presum[t-1][l-1];
}

int getOperations(int l, int r, int t, int b) {
    int operations = 0;

    operations += getOnes(l + 1, r - 1, t + 1, b - 1);      // get central part
    operations += b - t - 1 - getOnes(l, l, t + 1, b - 1);  // get left part
    operations += b - t - 1 - getOnes(r, r, t + 1, b - 1);  // get right part
    operations += r - l - 1 - getOnes(l + 1, r - 1, t, t);  // get top part
    operations += r - l - 1 - getOnes(l + 1, r - 1, b, b);  // get bottom part

    return operations;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int minRows = 5, minCols = 4;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            grid[i][j] = str[j-1] == '1' ? 1 : 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            presum[i][j] = presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1] + (grid[i][j] == 1 ? 1 : 0);
        }
    }

    int res = n * m;
    for (int l = 1; l + minCols - 1 <= m; l++) {
        for (int r = l + minCols - 1; r <= m; r++) {
            int cur = 2 * n * m;
            for (int b = minRows; b <= n; b++) {
                int nxt = cur;
                nxt += r - l - 1 - getOnes(l + 1, r - 1, b, b);
                nxt += grid[b-1][l] == 1 ? 0 : 1;
                nxt += grid[b-1][r] == 1 ? 0 : 1;
                nxt += 2 * getOnes(l + 1, r - 1, b - 1, b - 1) - (r - l - 1);
                cur = min(nxt, getOperations(l, r, b - minRows + 1, b));
                res = min(res, cur);
            }
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int min_corner_dist(int n, int m, int i, int j) {
    return max(
        n - 1 - i + m - 1 - j,
        max(
            n - 1 - i + j,
            max(
                i + m - 1 - j,
                i + j
            )
        )
    );
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res.push_back(min_corner_dist(n, m, i, j));
        }
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
#include <iostream>
#include <vector>
using namespace std;

static bool superior(vector<vector<int>>& points, int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (points[a][i] < points[b][i]) {
            cnt++;
        }
    }

    return cnt >= 3;
}

static void solve() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(5, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> points[i][j];
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (superior(points, i, index)) {
            index = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (superior(points, i, index)) {
            cout << "-1" << endl;
            return;
        }
    }

    cout << index + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
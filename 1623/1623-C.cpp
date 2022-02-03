#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

bool is_valid(vector<int>& stones, int m) {
    vector<int> copied_stones(stones.size(), 0);
    for (int i = 0; i < stones.size(); i++) {
        copied_stones[i] = stones[i];
    }

    for (int i = stones.size() - 1; i >= 0; i--) {
        if (copied_stones[i] < m) {
            return false;
        }
        if (i >= 2) {
            int given_unit = min(copied_stones[i] - m, stones[i]) / 3;
            copied_stones[i-1] += given_unit;
            copied_stones[i-2] += given_unit * 2;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> stones(n, 0);
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        r = max(r, stones[i]);
    }
    r++;
    int l = 0;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (is_valid(stones, m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
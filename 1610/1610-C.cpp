#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

bool meet_condition(vector<int>& a, vector<int>& b, int n, int x) {
    int smaller_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (smaller_cnt <= b[i] && x - 1 - smaller_cnt <= a[i]) {
            smaller_cnt++;
        }
    }

    return smaller_cnt >= x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int l = 1, r = n + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (meet_condition(a, b, n, m)) {
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
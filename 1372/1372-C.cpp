#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1;
    while (l <= n && a[l] == l) {
        l++;
    }

    if (l == n + 1) {
        cout << 0 << endl;
        return;
    }

    int r = n;
    while (r > l && a[r] == r) {
        r--;
    }

    bool is_matched = false;
    for (int i = l; i <= r; i++) {
        if (a[i] == i) {
            is_matched = true;
            break;
        }
    }

    if (is_matched) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
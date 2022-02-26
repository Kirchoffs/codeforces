#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int s = i + 1, e = n;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (a[m] + a[i] < l) {
                s = m + 1;
            } else {
                e = m;
            }
        }

        int range_s = s;
        s = range_s, e = n;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (a[m] + a[i] <= r) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        int range_e = s - 1;
        res += range_e - range_s + 1;
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
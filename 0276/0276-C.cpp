#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> diff(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        diff[l]++;
        diff[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i-1];
    }

    sort(diff.begin(), diff.end());
    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        res += (ll) a[i] * diff[i + 1];
    }

    cout << res << endl;
}

int main() {
    solve();
}
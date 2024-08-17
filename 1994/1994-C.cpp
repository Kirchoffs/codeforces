#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

int bs(const vector<ll>& a, int i, int x) {
    int l = i, r = a.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] - a[i - 1] <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> presum(n + 1);
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i - 1] + a[i - 1];
    }

    vector<ll> dp(n);
    dp[n - 1] = a[n - 1] <= x ? 1 : 0;
    for (int i = n - 2; i >= 0; i--) {
        int j = bs(presum, i + 1, x);
        j--;
        dp[i] = (j < n - 1 ? dp[j + 1] : 0) + j - i;
    }

    ll res = accumulate(dp.begin(), dp.end(), 0LL);
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}

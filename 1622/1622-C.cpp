#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll floor_division(ll dividend, ll divisor) {
    ll res = dividend / divisor;
    while (res * divisor > dividend) {
        res--;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<ll> presum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i-1] + arr[i-1];
    }

    ll res = LLONG_MAX;
    for (int y = 0; y < n; y++) {
        ll x = max(0LL, arr[0] - floor_division(k - presum[n - y] + arr[0], y + 1));
        res = min(res, x + y);
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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> time(n);
    vector<ll> health(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }

    vector<ll> min_require(n);
    for (int i = n - 1; i >= 0; i--) {
        min_require[i] = max(health[i], i < n - 1 ? min_require[i+1] - (time[i+1] - time[i]) : 0);
    }

    ll res = min_require[0] * (min_require[0] + 1) / 2;
    for (int i = 1; i < n; i++) {
        if (time[i] - time[i-1] >= min_require[i]) {
            res += min_require[i] * (min_require[i] + 1) / 2;
        } else {
            min_require[i] = min_require[i-1] + time[i] - time[i-1];
            res += (min_require[i] + min_require[i-1] + 1) * (time[i] - time[i-1]) / 2;
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
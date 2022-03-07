#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll mod = (ll) (1e9 + 7);

ll pow(ll base, ll power) {
    ll ret = 1;
    while (power != 0) {
        if (power % 2 != 0) {
            ret = (ret * base) % mod;
        }
        base = base * base % mod;
        power /= 2;
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> segments(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> segments[i][0] >> segments[i][1] >> segments[i][2];
    }

    ll or_val = 0;
    for (auto& segment: segments) {
        or_val |= segment[2];
    }

    cout << or_val * pow(2, n - 1) % mod << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
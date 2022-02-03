#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, l ,k;
    cin >> n >> l >> k;

    n++; // The destination can be regarded as a sign
    vector<ll> dists(n + 1, 0);
    vector<ll> limits(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> dists[i];
    }
    dists[n] = l;

    for (int i = 1; i < n; i++) {
        cin >> limits[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));
    for (int j = 0; j <= k; j++) {
        dp[1][j] = 0;
    }
    for (int i = 2; i <= n; i++) {          // Consider first i signs
        for (int j = 0; j <= k; j++) {      // At most drop k signs (not include the last sign)
            if (j > 0) {
                dp[i][j] = dp[i][j-1];
            }
            if (j > i - 2) {
                continue;
            }
            for (int t = 0; t <= j; t++) {  // Exactly t signs before i are dropped
                dp[i][j] = min(dp[i][j], dp[i-t-1][j-t] + (dists[i] - dists[i-t-1]) * limits[i-t-1]);
            }
        }
    }

    cout << dp[n][k] << endl;
}

int main() {
    solve();
}
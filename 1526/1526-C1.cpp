#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> potions(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> potions[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LLONG_MIN));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j];
            if (dp[i-1][j-1] != LLONG_MIN && dp[i-1][j-1] + potions[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + potions[i]);
            }
            if (dp[i][j] >= 0) {
                res = max(res, j);
            }
        }
    }

    cout << res << endl;
}

int main() {
    solve();
}
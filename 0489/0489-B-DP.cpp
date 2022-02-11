#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> boys(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> boys[i];
    }

    int m;
    cin >> m;
    vector<int> girls(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> girls[i];
    }

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (abs(boys[i] - girls[j]) <= 1) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    
    cout << dp[n][m];
}

int main() {
    solve();
}
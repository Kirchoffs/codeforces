#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve(vector<int>& dp) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int total_cost = 0;
    for (int target: b) {
        total_cost += dp[target];
    }

    k = min(k, total_cost);
    vector<int> knapsack(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j >= dp[b[i]]) {
                knapsack[j] = max(knapsack[j], knapsack[j - dp[b[i]]] + c[i]);
            }
        }
    }

    cout << knapsack[k] << endl;
}

int main() {
    const int limit = 1001;
    vector<int> dp(limit, INT_MAX);
    dp[1] = 0;
    for (int i = 1; i < limit; i++) {
        for (int x = 1; x <= i; x++) {
            if (i + i / x < limit) {
                dp[i + i / x] = min(dp[i + i / x], dp[i] + 1);
            }
        }
    }

    int t;
    cin >> t;
    while (t-- > 0) {
        solve(dp);
    }
}
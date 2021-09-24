#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(3, 0LL));
    dp[0][0] = max(arr[0], 0LL);
    dp[0][1] = max(arr[0] * x, 0LL);
    dp[0][2] = max(arr[0], 0LL);

    ll ret = max(dp[0][0], max(dp[0][1], dp[0][2]));
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0] > 0 ? dp[i-1][0] + arr[i] : arr[i], 0LL);
        dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]) + arr[i] * x, 0LL);
        dp[i][2] = max(max(dp[i-1][1], dp[i-1][2]) + arr[i], 0LL);

        ret = max(ret, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }

    cout << ret << endl;
}
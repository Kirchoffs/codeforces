#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int mod = 998244353;
    int n;
    cin >> n;

    vector<int> num_factors(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            num_factors[j]++;
        }
    }

    vector<int> dp(n + 1, 0);
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = (num_factors[i] + pre) % mod;
        pre = (pre + dp[i]) % mod;;
    }
    cout << dp[n] << endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
ll mod = 998244353;

ll combination(int n, int k, vector<vector<ll>>& cache) {
    if (k == 0) {
        return 1;
    }

    if (n < k) {
        return 0;
    }

    if (k == 1) {
        return n;
    }

    if (cache[n][k] != -1) {
        return cache[n][k];
    }

    cache[n][k] = (combination(n - 1, k - 1, cache) + combination(n - 1, k, cache)) % mod;

    return cache[n][k];
}

// A[n] = C(2n - 1, n) + B[n - 1]
// B[n] = C(2n - 2, n) + A[n - 1]
void solve() {
    int n;
    cin >> n;
    
    n /= 2;
    vector<ll> A(n + 1);
    vector<ll> B(n + 1);

    vector<vector<ll>> cache(2 * n + 1, vector<ll>(2 * n + 1, -1));
    for (int i = 1; i <= n; i++) {
        A[i] = (combination(i * 2 - 1, i, cache) + B[i - 1]) % mod;
        B[i] = (combination(i * 2 - 2, i, cache) + A[i - 1]) % mod;
    }

    cout << A[n] << " " << B[n] << " " << 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
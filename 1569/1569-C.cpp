#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll mod = 998244353;

ll factorial(int n, int exclusion) {
    ll res = 1;
    while (n > 0) {
        if (n != exclusion) {
            res = res * n % mod;
        }
        n--;
    }
    return res;
}

// If there are at least two indexes i, with a[i] = max(a), then it should always be nice
// If there are only one index i with a[i] = max(a), then there should be at least one index j after i
// with a[j] = max(a) - 1
void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_value = *max_element(a.begin(), a.end());
    int max_count = 0;
    int second_max_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == max_value) {
            max_count++;
        } else if (a[i] == max_value - 1) {
            second_max_count++;
        }
    }

    int res = factorial(n, -1);
    if (max_count < 2) {
        res = (res - factorial(n, second_max_count + 1) + mod) % mod;
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
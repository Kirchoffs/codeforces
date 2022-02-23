#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

#define LIMIT 1000000
vector<bool> is_prime(LIMIT + 1, true);

void init() {
    is_prime[1] = false;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime[a[i]] && a[i] != 1) {
            ll l = 1, r = 1;
            while (i - l * e >= 0 && a[i - l * e] == 1) {
                l++;
            }

            while (i + r * e < n && a[i + r * e] == 1) {
                r++;
            }

            res += l * r - 1;
        }
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    init();
    while (t-- > 0) {
        solve();
    }
}
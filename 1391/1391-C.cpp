#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
ll mod = (ll) (1e9 + 7);

ll permutation(ll n) {
    ll res = 1;
    ll i = 1;

    while (i <= n) {
        res = (res * i) % mod;
        i++;
    }

    return res;
}

ll fast_exponentiation(ll base, ll power) {
    ll res = 1;

    while (power != 0) {
        if (power % 2 == 1) {
            res = (res * base) % mod;
        }
        power /= 2;
        base = (base * base) % mod;
    }

    return res;
}

// ans = n! - 2^(n-1)
void solve() {
    ll n;
    cin >> n;

    ll res = permutation(n) - fast_exponentiation(2, n - 1);
    if (res < 0) {
        res += mod;
    }

    cout << res << endl;
}

int main() {
    solve();
}
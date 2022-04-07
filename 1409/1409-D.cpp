#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int get_sum(ll n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    ll n;
    int s;
    cin >> n >> s;

    if (get_sum(n) <= s) {
        cout << 0 << endl;
        return;
    }

    ll base = 1;
    ll res = 0;
    for (int i = 0; i < 18; i++) {
        int digit = n / base % 10;
        n += (10 - digit) % 10 * base;
        res += (10 - digit) % 10 * base;
        if (get_sum(n) <= s) {
            cout << res << endl;
            return;
        }
        base *= 10;
    }

    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
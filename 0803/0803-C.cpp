#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
using ll = long long;

static bool is_mul_greater(ll c, ll a, ll b) {
    if (c % a == 0) {
        return c / a > b;
    }
    return c / a >= b;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> candidates;
    for (ll d = 1; d <= (int)(sqrt(n)); d++) {
        if (n % d == 0) {
            candidates.push_back(d);
            if (n / d != d) {
                candidates.push_back(n / d);
            }
        }
    }
    sort(candidates.begin(), candidates.end(), greater<int>());

    for (ll candidate: candidates) {
        ll cur = n / candidate;
        ll sum = n;
        if (is_mul_greater(2 * cur, k + 2, k - 1)) {
            for (ll t = 1; t < k; t++) {
                cout << t * candidate << " ";
                sum -= t * candidate;
            }
            cout << sum << endl;
            return 0;
        }
    }
    cout << -1 << endl;;
}
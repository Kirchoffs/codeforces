#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int helper(ll x) {
    ll l = 0, r = 1e9 + 1;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (m * (m + 1) / 2 < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    ll path_sum = (l + 1) * l / 2;
    while ((path_sum - x) % 2 != 0) {
        l++;
        path_sum += l;
    }

    return l;
}

void solve() {
    ll x;
    cin >> x;
    
    cout << helper(abs(x)) << endl;
}

int main() {
    solve();
}
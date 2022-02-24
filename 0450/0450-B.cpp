#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

// f(i+1) = f(i) - f(i-1)
// [x], [y], y-x, -x, -y, x-y, [x], [y], ...
void solve() {
    ll mod = 1e9 + 7;
    ll a, b, n;
    cin >> a >> b >> n;

    vector<ll> candidates = {a, b, b-a, -a, -b, a-b};
    cout << (candidates[(n - 1) % 6] + mod * 2) % mod << endl;
}

int main() {
    solve();
}
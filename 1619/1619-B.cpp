#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    set<int> candidates;

    for (ll i = 1; i * i <= n; i++) {
        candidates.insert(i * i);
    }
    for (ll i = 1; i * i * i <= n; i++) {
        candidates.insert(i * i * i);
    }

    cout << candidates.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
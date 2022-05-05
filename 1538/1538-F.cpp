#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int l, r;
    cin >> l >> r;

    int res = 0;
    while (l != 0 || r != 0) {
        res += (r - l);
        r /= 10;
        l /= 10;
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
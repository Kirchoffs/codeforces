#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

// Count the number of (a, b, c) with 1 <= a <= b <= c <= n
// such that c^2 = a^2 + b^2 and c = a^2 - b

// c = b + 1
// a^2 = 2b + 1
void solve() {
    ll n;
    cin >> n;

    int res = 0;
    // Iterate a
    // a^2 = 2b + 1 >= 2a + 1              -> a >= 3
    // a^2 = 2b + 1 = 2c - 1 <= 2n - 1     -> a^2 <= 2n - 1
    for (int a = 3; a * a <= 2 * n - 1; a += 2) {
        res++;
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
#include <iostream>
using namespace std;

// n * m
// n = even, m = even
// n = odd, m = even
// n = even, m = odd
bool helper(int n, int m, int k) {
    if (n % 2 == 0 && m % 2 == 0) {
        return k % 2 == 0;
    } else if (n % 2 != 0 && m % 2 == 0) {
        return k >= m / 2 && (k - m / 2) % 2 == 0;
    } else {
        return helper(m, n, m * n / 2 - k);
    }
}


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (helper(n, m, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
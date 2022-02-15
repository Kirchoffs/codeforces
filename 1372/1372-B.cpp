#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int limit = (int) sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            int gcd = n / i;
            int x = 1 * gcd;
            int y = (i - 1) * gcd;
            cout << x << " " << y << endl;
            return;
        }
    }
    cout << 1 << " " << n - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    // res = 1 + 2 * 3 + 3 * 5 + 4 * 7 + ... + n * (2n - 1) = n * (n + 1) * (4n - 1) / 6
    int res = n * (n + 1) * (4 * n - 1) / 6;
    int cnt = n * 2;
    cout << res << " " << cnt << endl;
    for (int i = n; i >= 1; i--) {
        cout << 1 << " " << i << " ";
        for (int j = 1; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;

        cout << 2 << " " << i << " ";
        for (int j = 1; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}

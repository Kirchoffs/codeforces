#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int diff_zero = 0, diff_one = 0, same_zero = 0, same_one = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] == '0') {
                diff_zero++;
            } else {
                diff_one++;
            }
        } else {
            if (a[i] == '0') {
                same_zero++;
            } else {
                same_one++;
            }
        }
    }

    int res = n + 1;

    if (diff_one == diff_zero) {
        res = min(res, diff_one + diff_zero);
    }

    if (same_one > 0) {
        same_one--;
        if (same_one == same_zero) {
            res = min(res, same_one + same_zero + 1);
        }
    }

    cout << (res == n + 1 ? -1 : res) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
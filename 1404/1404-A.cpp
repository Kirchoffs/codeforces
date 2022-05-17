#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    bool is_balanced = true;
    int zero = 0, one = 0;
    for (int i = 0; i < k; i++) {
        char candidate = '?';
        for (int j = i; j < n; j += k) {
            if (s[j] != '?') {
                if (s[j] != candidate && candidate != '?') {
                    is_balanced = false;
                    break;
                }
                candidate = s[j];
            }
        }
        if (candidate != '?') {
            if (candidate == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (!is_balanced) {
            break;
        }
    }

    if (max(zero, one) > k / 2) {
        is_balanced = false;
    }

    if (is_balanced) {
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
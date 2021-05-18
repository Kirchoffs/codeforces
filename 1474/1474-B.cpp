#include <iostream>
using namespace std;

void solve() {
    int d;
    cin >> d;
    int p = 1 + d;
    for (; ; p++) {
        bool is_found = true;
        for (int j = 2; j * j <= p; j++) {
            if (p % j == 0) {
                is_found = false;
                break;
            }
        }
        if (is_found) {
            break;
        }
    }

    int q = p + d;
    for (; ; q++) {
        bool is_found = true;
        for (int j = 2; j * j <= q; j++) {
            if (q % j == 0) {
                is_found = false;
                break;
            }
        }
        if (is_found) {
            break;
        }
    }

    cout << min(1LL * p * q, 1LL * p * p * p) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
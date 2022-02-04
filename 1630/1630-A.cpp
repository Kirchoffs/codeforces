#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int compliment(int x, int n) {
    return n - 1 - x;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << i << " " << compliment(i, n) << endl;
        }
    } else if (k > 0 && k < n - 1) {
        cout << k << " " << n - 1 << endl;
        cout << compliment(k, n) << " " << 0 << endl;
        for (int i = 0; i < n / 2; i++) {
            if (i != 0 && i != k && i != compliment(k, n)) {
                cout << i << " " << compliment(i, n) << endl;
            }
        }
    } else {
        if (k == 3) {
            cout << -1 << endl;
        } else {
            cout << n - 1 << " " << n - 2 << endl;
            cout << n - 3 << " " << 1 << endl;
            cout << 0 << " " << 2 << endl;
            for (int i = 0; i < n / 2; i++) {
                if (i != 0 && i != 1 && i != 2) {
                    cout << i << " " << compliment(i, n) << endl;
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
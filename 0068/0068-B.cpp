#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double l = 0, r = 1001;
    double delta = 1e-6;
    while (r - l > delta) {
        double m = l + (r - l) / 2;
        double less = 0, more = 0;
        for (int energy: a) {
            if (energy < m) {
                less += m - energy;
            } else {
                more += (energy - m) * (100 - k) / 100;
            }
        }

        if (more > less) {
            l = m;
        } else {
            r = m;
        }
    }
    cout.precision(20);
    cout << fixed << l << endl;
}

int main() {
    solve();
}
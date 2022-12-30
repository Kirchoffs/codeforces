#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll max_freq = a.back();
    ll max_freq_cnt = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (a[i] == max_freq) {
            max_freq_cnt++;
        } else {
            break;
        }
    }

    if ((max_freq - 1) * k + max_freq_cnt <= n) {
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
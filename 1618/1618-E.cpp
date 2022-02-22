#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = cities[i] - cities[(i - 1 + n) % n];
    }

    ll sum = 0;
    for (int city: cities) {
        sum += city;
    }
    ll coef = n * (n + 1) / 2;
    if (sum % coef != 0) {
        cout << "NO" << endl;
        return;
    }

    ll total = sum / coef;
    vector<ll> res;
    for (int i = 0; i < n; i++) {
        if ((total - diff[i]) % n != 0 || total <= diff[i]) {
            cout << "NO" << endl;
            return;
        } else {
            res.push_back((total - diff[i]) / n);
        }
    }

    cout << "YES" << endl;
    for (int re: res) {
        cout << re << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
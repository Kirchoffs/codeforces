#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int bs(const vector<ll>& a, int x) {
    int l = 0, r = a.size();

    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l - 1;
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> a(k + 1);
    a[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    vector<ll> b(k + 1);
    b[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    vector<ll> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    for (ll query : queries) {
        int last_idx = bs(a, query);
        if (a[last_idx] == query) {
            cout << b[last_idx] << endl;
            continue;
        }

        int next_idx = last_idx + 1;

        ll dist_to_last = query - a[last_idx];
        ll time_to_last = dist_to_last * (b[next_idx] - b[last_idx]) / (a[next_idx] - a[last_idx]);

        cout << b[last_idx] + time_to_last << " ";
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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    int t = n * m;
    vector<pair<int, int>> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < t; i++) {
        a[i].second = -a[i].second;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        sort(a.begin() + (m * i), a.begin() + (m * i + m));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                if (a[m * i + k].second > a[m * i + j].second) {
                    res++;
                }
            }
        }
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
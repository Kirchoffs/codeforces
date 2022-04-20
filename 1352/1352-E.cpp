#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int res = 0;
    for (int l = 0; l < n; l++) {
        int sum = a[l];
        for (int r = l + 1; r < n; r++) {
            sum += a[r];
            if (sum <= n) {
                res += cnt[sum];
                cnt[sum] = 0;
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
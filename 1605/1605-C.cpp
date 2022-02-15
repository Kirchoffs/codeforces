#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(3);
        cnt[str[i] - 'a']++;
        for (int j = i + 1; j < min(n, i + 7); j++) {
            cnt[str[j] - 'a']++;

            if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                res = min(res, j - i + 1);
            }
        }
    }

    if (res != INT_MAX) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
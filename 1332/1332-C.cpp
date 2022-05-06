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

    int l = 0, r = k - 1;
    int res = 0;
    while (l <= r) {
        vector<int> cnt(26, 0);

        int l_idx = l, r_idx = r;
        int max_count = 0;
        for (int i = 0; i < n / k; i++) {
            cnt[s[l_idx] - 'a']++;
            cnt[s[r_idx] - 'a']++;
            max_count = max(max_count, max(cnt[s[l_idx] - 'a'], cnt[s[r_idx] - 'a']));
            l_idx += k;
            r_idx += k;
        }

        if (l == r) {
            res += (n / k * 2 - max_count) / 2;
        } else {
            res += n / k * 2 - max_count;
        }

        l++;
        r--;
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
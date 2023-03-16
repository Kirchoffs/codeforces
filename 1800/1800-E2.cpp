#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k; // k is always 3

    string s, t;
    cin >> s >> t;

    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        if (i + k < n || i >= k) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        } else {
            if (s[i] != t[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (int v: cnt) {
        if (v != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
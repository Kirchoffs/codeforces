#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;
using ll = long long;

int bs(vector<int>& a, int target) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l - 1;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    ll pre = 0;
    stack<int> stk;
    vector<ll> res(n + 1, -1);
    for (int i = 0; i <= n; i++) {
        if (i > 0 && cnt[i-1] == 0) {
            if (stk.empty()) {
                break;
            }
            int j = stk.top();
            stk.pop();
            pre += i - 1 - j;
        }
        res[i] = pre + cnt[i];
        while (i > 0 && cnt[i-1] > 1) {
            cnt[i-1]--;
            stk.push(i-1);
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << res[i] << " ";
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
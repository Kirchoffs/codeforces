#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int count_bit(ll num) {
    int cnt = 0;
    while (num != 0) {
        num = num & (num - 1);
        cnt++;
    }
    return cnt;
}

void build_fatorials(ll n, vector<ll>& factorials) {
    ll cur = 1, i = 1;
    while (cur <= n) {
        factorials.push_back(cur);
        cur *= (i + 1);
        i++;
    }
}

void solve() {
    ll n;
    
    cin >> n;
    vector<ll> factorials;
    build_fatorials(n, factorials);

    int len = factorials.size();
    int res = INT_MAX;
    for (int state = 0; state < (1 << len); state++) {
        ll sum = 0;
        int cur_cnt = 0;
        for (int bit = 0; bit < len; bit++) {
            if ((state & (1 << bit)) != 0) {
                sum += factorials[bit];
                cur_cnt++;
            }
        }
        if (sum <= n) {
            res = min(res, cur_cnt + count_bit(n - sum));
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
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;

ll n_choose_2(int n) {
    return (ll) n * (n - 1) / 2;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll mask = (1 << k) - 1;
    unordered_map<ll, int> cnts;
    cnts[0] = 1L;
    ll pre_xor = 0;
    for (ll num: a) {
        pre_xor = pre_xor ^ num;
        cnts[min(pre_xor, pre_xor ^ mask)]++;
    }

    ll res = n_choose_2(n + 1);
    for (auto const& cnt: cnts) {
        res -= n_choose_2(cnt.second / 2) + n_choose_2(cnt.second - cnt.second / 2);
    }

    cout << res << endl;
}
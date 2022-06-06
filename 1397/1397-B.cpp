#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

// |a| + |b| = max(|a + b|, |a - b|)
//
// if x1 < x2, y1 < y2
// then |x1 - y2| + |x2 - y1|
//    = max(|(x1 - y2) + (x2 - y1)| + |(x1 - y2) - (x2 - y1)|)
//    = max(|(x1 - y2) + (x2 - y1)| + |(x1 - x2) + (y1 - y2)|)
//   >= max(|(x1 - y2) + (x2 - y1)| + |(x2 - x1) + (y1 - y2)|)
//    = max(|(x1 - y1) + (x2 - y2)| + |(x2 - y2) - (x1 - y1)|)
//    = max(|(x1 - y1) + (x2 - y2)| + |(x1 - y1) - (x2 - y2)|)
//    = |x1 - y1| + |x2 - y2|
void solve() {
    ll limit = (ll)(1e15);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    if (n <= 2) {
        cout << a[0] - 1 << endl;
    } else {
        ll res = accumulate(a.begin(), a.end(), 0LL) - n; // res <= 10^14
        for (ll c = 2; ; c++) {
            ll cur_cost = 0, cur_pow = 1;
            for (int i = 0; i < n; i++) {
                cur_cost = cur_cost + abs(a[i] - cur_pow);
                if (cur_cost >= limit) {
                    break;
                }
                cur_pow = cur_pow * c;
            }
            if (cur_cost >= limit) {
                break;
            }
            res = min(res, cur_cost);
        }
        cout << res << endl;
    }
}

int main() {
    solve();
}
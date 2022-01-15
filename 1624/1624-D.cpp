#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    string input;
    cin >> n >> k >> input;
    
    vector<int> cnts(26, 0);
    for (char ch: input) {
        cnts[ch - 'a']++;
    }

    int pair_cnt = 0;
    int single_cnt = 0;
    for (int cnt: cnts) {
        pair_cnt += cnt / 2;
        single_cnt += cnt % 2;
    }

    int res = 2 * (pair_cnt / k);
    single_cnt += 2 * (pair_cnt % k);
    if (single_cnt >= k) {
        res++;
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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> res(n);
    vector<int> end_with_zero;
    vector<int> end_with_one;
    for (int i = 0; i < n; i++) {
        int new_idx = end_with_zero.size() + end_with_one.size();
        if (s[i] == '0') {
            if (end_with_one.empty()) {
                end_with_zero.push_back(new_idx);
            } else {
                new_idx = end_with_one.back();
                end_with_one.pop_back();
                end_with_zero.push_back(new_idx);
            }
        } else {
            if (end_with_zero.empty()) {
                end_with_one.push_back(new_idx);
            } else {
                new_idx = end_with_zero.back();
                end_with_zero.pop_back();
                end_with_one.push_back(new_idx);
            }
        }
        res[i] = new_idx;
    }

    cout << end_with_zero.size() + end_with_one.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] + 1 << " ";
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
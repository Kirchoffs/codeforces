#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll s;
    cin >> n >> s;

    vector<pair<int, int>> employees(n);
    ll base_cost = 0;
    for (int i = 0; i < n; i++) {
        cin >> employees[i].first >> employees[i].second;
        base_cost += employees[i].first;
    }

    sort(employees.begin(), employees.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    });

    int l = 0, r = 1e9 + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        ll cost = base_cost;
        int cnt = 0;
        for (const auto& employee: employees) {
            if (employee.second >= m) {
                cnt++;
                cost += max(0, m - employee.first);

                if (cnt * 2 - 1 == n) {
                    break;
                }
            }
        }
        if (cnt * 2 - 1 == n && cost <= s) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
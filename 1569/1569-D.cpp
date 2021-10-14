#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

ll helper(vector<PII>& people, vector<int>& axis) {
    ll res = 0;
    int k = people.size();
    int m = axis.size();

    sort(people.begin(), people.end(), [](PII& a, PII& b) {
        return a.first < b.first;
    });
    vector<PII> record(k);
    vector<int> y_count(m, 0);
    int u = 0;
    while (u < k) {
        int v = u;
        while (v < k && people[v].first == people[u].first) {
            v++;
        }

        for (int i = u; i < v; i++) {
            int r = int(lower_bound(axis.begin(), axis.end(), people[i].second) - axis.begin());
            int l = r;
            if (axis[l] > people[i].second) {
                l--;
            }
            record[i] = {l, r};
        }

        for (int i = u; i < v; i++) {
            if (record[i].first < record[i].second) {
                res += y_count[record[i].first];
            }
        }

        for (int i = u; i < v; i++) {
            if (record[i].first < record[i].second) {
                y_count[record[i].first]++;
            }
        }

        u = v;
    }

    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> x(n, 0);
    vector<int> y(m, 0);
    vector<PII> people(k);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> people[i].first;
        cin >> people[i].second;
    }

    ll res = 0;

    res += helper(people, y);
    
    for (int i = 0; i < k; i++) {
        swap(people[i].first, people[i].second);
    }
    res += helper(people, x);

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
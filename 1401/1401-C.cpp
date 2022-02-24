#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_val = *min_element(a.begin(), a.end());
    vector<int> indexes;
    vector<int> sorted_indexes;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % min_val == 0) {
            indexes.push_back(i);
            sorted_indexes.push_back(i);
        }
    }

    sort(sorted_indexes.begin(), sorted_indexes.end(), [&](int i, int j) {
        if (a[i] < a[j]) {
            return true;
        }
        return false;
    });

    vector<int> b(a.begin(), a.end());
    for (int i = 0; i < indexes.size(); i++) {
        b[indexes[i]] = a[sorted_indexes[i]];
    }

    for (int i = 1; i < b.size(); i++) {
        if (b[i] < b[i-1]) {
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
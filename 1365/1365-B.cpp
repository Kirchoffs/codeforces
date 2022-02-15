#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

bool is_sorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (is_sorted(a)) {
        cout << "Yes" << endl;
        return;
    }

    int one_cnt = 0, zero_cnt = 0;
    for (int i = 0; i < n; i++) {
        one_cnt += b[i] == 1 ? 1 : 0;
        zero_cnt += b[i] == 0 ? 1 : 0;
    }

    if (one_cnt > 0 && zero_cnt > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
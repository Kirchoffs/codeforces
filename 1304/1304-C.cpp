#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> customers(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> customers[i][0] >> customers[i][1] >> customers[i][2]; // t, l, h
    }

    int current_max = m, current_min = m;
    int prev = 0;
    bool is_valid = true;
    for (int i = 0; i < n; i++) {
        current_max = current_max + (customers[i][0] - prev);
        current_min = current_min - (customers[i][0] - prev);

        if (current_max < customers[i][1] || current_min > customers[i][2]) {
            is_valid = false;
            break;
        }

        current_max = min(current_max, customers[i][2]);
        current_min = max(current_min, customers[i][1]);
        prev = customers[i][0];
    }

    if (is_valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
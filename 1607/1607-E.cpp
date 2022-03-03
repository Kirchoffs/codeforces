#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int ans_x = 1, ans_y = 1;
    int delta_x = 0, delta_y = 0;
    int min_delta_x = 0, min_delta_y = 0, max_delta_x = 0, max_delta_y = 0;
    for (char c: s) {
        if (c == 'L') {
            delta_y--;
        } else if (c == 'R') {
            delta_y++;
        } else if (c == 'U') {
            delta_x--;
        } else {
            delta_x++;
        }

        min_delta_x = min(min_delta_x, delta_x);
        min_delta_y = min(min_delta_y, delta_y);
        max_delta_x = max(max_delta_x, delta_x);
        max_delta_y = max(max_delta_y, delta_y);

        // x + max_delta_x <= n && x + min_delta_x >= 1
        // y + max_delta_y <= n && y + min_delta_y >= 1
        int x = n - max_delta_x, y = m - max_delta_y;

        if (x >= 1 && x <= n && x + min_delta_x >= 1 && x + max_delta_x <= n && 
            y >= 1 && y <= m && y + min_delta_y >= 1 && y + max_delta_y <= m) {
                ans_x = x;
                ans_y = y;
        } else {
            break;
        }
    }

    cout << ans_x << " " << ans_y << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
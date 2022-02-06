#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> mice(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> mice[i];
    }

    sort(mice.begin(), mice.end());
    int cat_dist = 0;
    int mouse_index = k - 1;
    while (mouse_index >= 0) {
        if (cat_dist < mice[mouse_index]) {
            cat_dist += n - mice[mouse_index];
            mouse_index--;
        } else {
            break;
        }
    }
    
    cout << k - mouse_index - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
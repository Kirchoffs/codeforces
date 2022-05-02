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
    
    int target = 0;
    for (int i = 0; i < n; i++) {
        target ^= a[i];
    }

    if (target == 0) {
        cout << "YES" << endl;
    } else {
        int tmp = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            tmp ^= a[i];
            if (tmp == target) {
                tmp = 0;
                cnt++;
            }
        }

        if (tmp == 0 && cnt > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
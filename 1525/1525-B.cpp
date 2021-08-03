#include <iostream>
#include <vector>
using namespace std;

static void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    bool is_sorted = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        cout << 0 << endl;
        return;
    }

    if (a[0] == n && a[n-1] == 1) {
        cout << 3 << endl;
    } else if (a[0] != 1 && a[n-1] != n) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
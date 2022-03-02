#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= b[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        res[i] = l;
    }

    for (int re: res) {
        cout << re << " ";
    }
    cout << endl;
}

int main() {
    solve();
}
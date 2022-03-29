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

    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
        int idx = -1;
        for (int j = 0; j <= i; j++) {
            if (a[j] == i + 1) {
                idx = j;
                break;
            }
        }
        res[i] = (idx + 1) % (i + 1);

        vector<int> helper(i + 1);
        for (int j = 0; j <= i; j++) {
            helper[(j + i + 1 - res[i]) % (i + 1)] = a[j];
        }

        for (int j = 0; j <= i; j++) {
            a[j] = helper[j];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
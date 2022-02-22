#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

// xoo xoo xoo ... b
// is equivalent to
// ... xoo xoo xoo b

// if no bound
// xoo xoo xoo ... x(oo)
// so we can add k more tables here
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> indices;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            indices.push_back(i);
        }
    }

    int res = 0;
    for (int i = 1; i < indices.size(); i++) {
        int delta = indices[i] - (i > 0 ? indices[i-1] : -1) - 1;
        res += max((delta + 1) / (k + 1) - 1, 0);
    }

    if (indices.size() > 0) {
        res += indices[0] / (k + 1);
        res += (n - 1 - indices[indices.size() - 1]) / (k + 1);
    } else {
        res += max((n + k) / (k + 1), 1);
    }
    
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
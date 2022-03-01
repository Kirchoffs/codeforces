#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    sort(q.begin(), q.end());
    long wait_time = q[0];
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (wait_time <= q[i]) {
            res++;
            wait_time += q[i];
        }
    }

    cout << res << endl;
}

int main() {
    solve();
}
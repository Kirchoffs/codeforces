#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, l;
    cin >> n >> l;

    vector<double> lanterns(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> lanterns[i];
    }
    sort(lanterns.begin(), lanterns.end());
    double res = max(lanterns[0], l - lanterns[n - 1]);
    for (int i = 0; i < n - 1; i++) {
        res = max(res, (lanterns[i + 1] - lanterns[i]) / 2.0);
    }
    cout.precision(20);
    // cout << fixed << res << endl;
    cout << res << endl;
    cout << fixed << res << endl;
}

int main() {
    solve();
}
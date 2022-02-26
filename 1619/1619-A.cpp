#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    if (n % 2 != 0) {
        cout << "NO" << endl;
    } else {
        if (s.substr(0, n / 2) == s.substr(n / 2)) {
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
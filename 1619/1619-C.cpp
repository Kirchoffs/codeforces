#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    string a, s;
    cin >> a >> s;

    int i = a.length() - 1, j = s.length() - 1;
    string b = "";
    while (i >= 0 && j >= 0) {
        if (a[i] <= s[j]) {
            b.push_back('0' + s[j] - a[i]);
            i--;
            j--;
        } else {
            if (j < 1 || s[j-1] != '1') {
                cout << -1 << endl;
                return;
            }
            b.push_back('0' + 10 + s[j] - a[i]);
            i--;
            j -= 2;
        }
    }

    if (i >= 0) {
        cout << -1 << endl;
    } else {
        while (j >= 0) {
            b.push_back(s[j]);
            j--;
        }
        while (b.length() > 1 && b[b.length() - 1] == '0') {
            b.pop_back();
        }
        reverse(b.begin(), b.end());
        cout << b << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
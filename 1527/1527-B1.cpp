#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count_zero = 0;
    for (int i = 0; i < n; i++) {
        count_zero += (s[i] == '0' ? 1 : 0);
    }

    if (count_zero % 2 == 0 || count_zero == 1) {
        cout << "BOB" << endl;
        return;
    }

    cout << "ALICE" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
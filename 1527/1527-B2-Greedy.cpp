#include <iostream>
using namespace std;

bool is_palindrome(string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count_zero = 0;
    for (int i = 0; i < n; i++) {
        count_zero += (s[i] == '0' ? 1 : 0);
    }

    if (is_palindrome(s)) {
        if (count_zero % 2 == 0 || count_zero == 1) {
            cout << "BOB" << endl;
            return;
        }

        cout << "ALICE" << endl;
    } else {
        if (count_zero == 2 && n % 2 == 1 && s[n/2] == '0') {
            cout << "DRAW" << endl;
            return;
        }
        cout << "ALICE" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
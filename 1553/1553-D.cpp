#include <iostream>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int index_s = s.length() - 1;
    int index_t = t.length() - 1;

    while (index_t >= 0 && index_s >= 0) {
        if (t[index_t] == s[index_s]) {
            index_t--;
            index_s--;

            if (index_t == -1) {
                cout << "YES" << endl;
                return;
            }
        } else {
            index_s -= 2;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
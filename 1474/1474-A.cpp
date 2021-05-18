#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string b;
    cin >> b;

    string res = "1";
    for (int i = 1; i < n; i++) {
        int pre = (res[i-1] - '0') + (b[i-1] - '0');
        if (b[i] - '0' + 1 != pre) {
            res += "1";
        } else {
            res += "0";
        }
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
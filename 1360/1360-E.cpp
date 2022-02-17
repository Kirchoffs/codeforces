#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> matrix(n);

    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                if (matrix[i+1][j] != '1' && matrix[i][j+1] != '1') {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
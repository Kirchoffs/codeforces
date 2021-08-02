#include <iostream>
using namespace std;

/*
 * number of pair (0, 0)
 * number of pair (0, 1)
 * if mid character exists (length of string is odd) and it is '0'
 * if previous move was operation reverse
 * 
 * dp = Alice - Bob
 */ 
int dp[501][501][2][2];
void pre_compute() {
    for (int i = 0;i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 1; l >= 0; l--) {
                    dp[i][j][k][l] = 1e9;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 1; l >= 0; l--) {
                    if (l == 0 && j > 0) dp[i][j][k][l] = min(dp[i][j][k][l], -dp[i][j][k][1]);
                    if (i > 0) dp[i][j][k][l] = min(dp[i][j][k][l], 1 - dp[i-1][j+1][k][0]);
                    if (j > 0) dp[i][j][k][l] = min(dp[i][j][k][l], 1 - dp[i][j-1][k][0]);
                    if (k == 1) dp[i][j][k][l] = min(dp[i][j][k][l], 1 - dp[i][j][0][0]);
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int num_zero_zero = 0, num_zero_one = 0;
    int mid = 0;
    int pre = 0;

    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i] && s[i] == '0') {
            num_zero_zero++;
        } else if (s[i] != s[n - 1 - i]) {
            num_zero_one++;
        }
    }

    if (n % 2 != 0 && s[n/2] == '0') {
        mid = 1;
    }

    if (dp[num_zero_zero][num_zero_one][mid][pre] < 0) {
        cout << "ALICE" << endl;
    } else if (dp[num_zero_zero][num_zero_one][mid][pre] > 0) {
        cout << "BOB" << endl;
    } else {
        cout << "DRAW" << endl;
    }
}

int main() {
    pre_compute();
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
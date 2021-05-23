#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> starts;
    vector<int> ends;
    for (int i = 0; i < n; i++) {
        int seat;
        cin >> seat;
        if (seat == 1) {
            starts.push_back(i + 1);
        } else {
            ends.push_back(i + 1);
        }
    }
    int starts_size = starts.size();
    int ends_size = ends.size();
    // dp[i][j]: i >= j
    vector<vector<int>> dp(ends_size + 1, vector<int>(starts_size + 1, 0));
    for (int i = 1; i <= ends_size; i++) {
        for (int j = 1; j <= min(i, starts_size); j++) {
            dp[i][j] = dp[i-1][j-1] + abs(ends[i-1] - starts[j-1]);
            if (i > j) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }
    }
    cout << dp[ends_size][starts_size] << endl;
}

int main() {
    solve();
}
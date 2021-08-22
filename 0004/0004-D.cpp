#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<vector<int>> envelopes;
    for (int i = 0; i < n; i++) {
        int wi, hi;
        cin >> wi >> hi;
        if (wi > w && hi > h) {
            envelopes.push_back({wi, hi, i + 1});
        }
    }

    if (envelopes.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return (long long)a[0] * a[1] < (long long)b[0] * b[1];
    });

    vector<int> dp(envelopes.size(), 1);
    vector<int> pre(envelopes.size(), -1);
    int res = 1;
    int end = 0;
    for (int i = 1; i < envelopes.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                if (dp[i] < dp[j] + 1) {
                    pre[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (res < dp[i]) {
            res = dp[i];
            end = i;
        }
    }
    
    stack<int> candidates;
    while (end != -1) {
        candidates.push(end);
        end = pre[end];
    }

    cout << res << endl;

    while (!candidates.empty()) {
        cout << envelopes[candidates.top()][2] << " ";
        candidates.pop();
    }

    cout << endl;
}
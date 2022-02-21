#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> indegree(n + 1, 0);
    vector<vector<int>> neighbors(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        indegree[u]++;
        indegree[v]++;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] <= 1) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty() && k > 0) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front();
            q.pop();
            cnt++;
            for (int nxt: neighbors[cur]) {
                indegree[nxt]--;
                if (indegree[nxt] == 1) {
                    q.push(nxt);
                }
            }
        }
        k--;
    }

    cout << n - cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
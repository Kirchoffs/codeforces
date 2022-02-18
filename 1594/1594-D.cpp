#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

bool dfs(
    vector<int>& visited, vector<vector<int>>& same, vector<vector<int>>& diff, 
    int cur, int& cnt_one, int& cnt_two, int group) {
    if (visited[cur] != 0) {
        if (visited[cur] == group) {
            return true;
        }
        return false;
    }

    visited[cur] = group;
    if (group == 1) {
        cnt_one++;
    } else {
        cnt_two++;
    }

    for (int nxt: same[cur]) {
        if (!dfs(visited, same, diff, nxt, cnt_one, cnt_two, group)) {
            return false;
        }
    }

    for (int nxt: diff[cur]) {
        if (!dfs(visited, same, diff, nxt, cnt_one, cnt_two, -group)) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> same(n + 1);
    vector<vector<int>> diff(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        string w;
        cin >> u >> v >> w;
        if (w == "imposter") {
            diff[u].push_back(v);
            diff[v].push_back(u);
        } else {
            same[u].push_back(v);
            same[v].push_back(u);
        }
    }
    vector<int> visited(n + 1, 0);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] != 0) {
            continue;
        }
        int cnt_one = 0, cnt_two = 0;
        if (dfs(visited, same, diff, i, cnt_one, cnt_two, 1)) {
            res += max(cnt_one, cnt_two);
        } else {
            cout << -1 << endl;
            return;
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
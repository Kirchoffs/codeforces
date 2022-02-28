#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int dfs(vector<vector<int>>& graph, vector<int>& values, int cur, int pre, int total_xor, bool& first, bool& second) {
    int cur_xor = values[cur];
    for (int nxt: graph[cur]) {
        if (nxt != pre) {
            int nxt_xor = dfs(graph, values, nxt, cur, total_xor, first, second);
            if (first && second) {
                return 0;
            }
            cur_xor ^= nxt_xor;
        }
    }
    if (cur_xor == total_xor) {
        if (!first) {
            first = true;
        } else {
            second = true;
        }
        return 0;
    }
    return cur_xor;
}

// If we can divide into m components with equal xor value
// if m = 2, the xor of all value must be 0, in this situation, we can remove any edge to break the tree
// if m > 2, we can always merge 3 components into a new one, and still hold the condition
//   if m is even, then xor of all value is 0
//   if m is odd, we can just consider 3 components, and each components's xor value is equal to the all values' xor
//   so we just need to search for 2 edges
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int total_xor = 0;
    for (int value: a) {
        total_xor ^= value;
    }

    if (total_xor == 0) {
        cout << "YES" << endl;
        return;
    } else if (k < 3) {
        cout << "NO" << endl;
        return;
    }

    bool first = false, second = false;
    dfs(graph, a, 1, 0, total_xor, first, second);

    if (first && second) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
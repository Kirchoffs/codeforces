#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int inf = 1e9;

// You can also union find to connect all edges, so that no need to re-build the graph and do the DFS
void dfs(vector<vector<pair<int, int>>>& graph, int state, vector<bool>& visited, int cur) {
    visited[cur] = true;
    for (auto& edge: graph[cur]) {
        int nxt = edge.first, val = edge.second;
        if (!visited[nxt] && (state | val) == state) {
            dfs(graph, state, visited, nxt);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int state = 1;
    int bit = 0;
    while (state < inf) {
        state = (state << 1) + 1;
        bit++;
    }
    
    for (int i = bit; i >= 0; i--) {
        vector<bool> visited(n + 1, false);
        state -= (1 << i);
        dfs(graph, state, visited, 1);
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                state += (1 << i);
                break;
            }
        }
    }

    cout << state << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
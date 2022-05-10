#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int idx, vector<int>& nodes) {
    if (visited[idx]) {
        return;
    }
    visited[idx] = true;
    nodes.push_back(idx);
    for (int nxt: graph[idx]) {
        dfs(graph, visited, nxt, nodes);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int res = 0;
    vector<bool> visited(n + 1);
    vector<int> nodes;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            nodes.clear();
            dfs(graph, visited, i, nodes);
            bool is_cycle = true;
            for (int node: nodes) {
                if (degree[node] != 2) {
                    is_cycle = false;
                    break;
                }
            }
            if (is_cycle) {
                res++;
            }
        }
    }

    cout << res << endl;
}

int main() {
    solve();
}
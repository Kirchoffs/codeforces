#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void dfs(vector<vector<int>>& graph, int n, int cur, int pre,
    vector<int>& primes, int choice, vector<int>& res, 
    map<ll, int> indices) {
    for (int neighbor: graph[cur]) {
        if (neighbor != pre) {
            choice = (choice + 1) % 2;
            res[indices[(ll) cur * (n + 1) + neighbor]] = primes[choice];
            dfs(graph, n, neighbor, cur, primes, choice, res, indices);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    map<ll, int> indices;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        indices[(ll) u * (n + 1) + v] = i;
        indices[(ll) v * (n + 1) + u] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (graph[i].size() > 2) {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> primes = {2, 3};
    vector<int> res(n - 1, 0);

    dfs(graph, n, 1, -1, primes, -1, res, indices);
    for (int i = 0; i < n - 1; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
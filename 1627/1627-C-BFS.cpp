#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

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
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push({1, -1});
    visited[1] = true;

    while (!q.empty()) {
        auto& state = q.front();
        q.pop();
        int cur = state.first;
        int choice = state.second;
        for (int& nxt: graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                choice = (choice + 1) % 2;
                res[indices[(ll) cur * (n + 1) + nxt]] = primes[choice];
                q.push({nxt, choice});
            }
        }
    }

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
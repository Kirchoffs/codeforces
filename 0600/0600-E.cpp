#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void dfs_size(vector<vector<int>>& adj, vector<int>& sz, int pre, int cur) {
    sz[cur] = 1;
    for (int child: adj[cur]) {
        if (child != pre) {
            dfs_size(adj, sz, cur, child);
            sz[cur] += sz[child];
        }
    }
}

void update(vector<int>& colors, 
            vector<int>& cnt, 
            vector<ll>& ans, 
            int& max_frequency, 
            int cur, 
            int delta) {
    ans[cnt[colors[cur]]] -= colors[cur];
    cnt[colors[cur]] += delta;
    ans[cnt[colors[cur]]] += colors[cur];
    max_frequency = max(max_frequency, cnt[colors[cur]]);
}

int dfs(vector<vector<int>>& adj, 
        vector<int>& colors,
        vector<int>& sz, 
        vector<int>& cnt,
        vector<vector<int>>& subtree, 
        vector<ll>& ans,
        vector<ll>& res,
        int pre,
        int cur, 
        bool keep) {
    int max_size = -1, max_child = -1;
    int max_frequency = -1;
    for (int child: adj[cur]) {
        if (child != pre && max_size < sz[child]) {
            max_size = sz[child];
            max_child = child;
        }
    }

    for (int child: adj[cur]) {
        if (child != pre && child != max_child) {
            dfs(adj, colors, sz, cnt, subtree, ans, res, cur, child, false);
        }
    }

    if (max_child != -1) {
        max_frequency = max(max_frequency, dfs(adj, colors, sz, cnt, subtree, ans, res, cur, max_child, true));
        swap(subtree[cur], subtree[max_child]);
    }
    subtree[cur].push_back(cur);
    update(colors, cnt, ans, max_frequency, cur, 1);

    for (int child: adj[cur]) {
        if (child != pre && child != max_child) {
            for (int grand_child: subtree[child]) {
                update(colors, cnt, ans, max_frequency, grand_child, 1);
                subtree[cur].push_back(grand_child);
            }
        }
    }

    res[cur] = ans[max_frequency];
    if (!keep) {
        for (int child: subtree[cur]) {
            update(colors, cnt, ans, max_frequency, child, -1);
        }
    }

    return max_frequency;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> colors(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int parent;
        int child;
        cin >> parent >> child;
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }

    vector<int> sz(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    vector<vector<int>> subtree(n + 1);
    vector<ll> ans(n + 1, 0);
    vector<ll> res(n + 1, 0);

    dfs_size(adj, sz, 0, 1);
    dfs(adj, colors, sz, cnt, subtree, ans, res, 0, 1, true);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int dfs(vector<int>& a, int n, int idx, vector<int>& cache) {
    if (idx >= n) {
        return 0;
    }

    if (cache[idx] != -1) {
        return cache[idx];
    }

    int ret = INT_MAX;
    int cnt = 0;
    for (int nxt = idx; nxt < idx + 2 && nxt < n; nxt++) {
        if (a[nxt] == 1) {
            cnt++;
        }
        ret = min(ret, min(dfs(a, n, nxt + 2, cache) + cnt, dfs(a, n, nxt + 3, cache) + cnt));
    }

    cache[idx] = ret;
    return ret;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> cache(n, -1);
    cout << dfs(a, n, 0, cache) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
#include <iostream>
#include <vector>
using namespace std;

static int cycle_count(vector<int>& graph, int n) {
    int cnt = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        int index = i;
        while (!used[index]) {
            used[index] = true;
            index = graph[index];
        }
        cnt++;
    }
    return cnt;
}

static bool check(vector<int>& target, int n, int m, int k) {
    vector<int> graph(n, 0);
    // graph:
    // element -> element
    for (int i = 0; i < n; i++) {
        graph[target[i]] = (i - k + n) % n;
    }
 		
 	return n - cycle_count(graph, n) <= m;
}

static void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> target(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> target[i];
        target[i]--;
    }

    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        if (i >= target[i]) {
            cnt[i - target[i]]++;
        } else {
            cnt[i + n - target[i]]++;
        }
    }

    // not_matched <= 2 * m
    // matched >= n - 2 * m, m <= n / 3
    // => matched > n / 3

    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (cnt[i] >= n / 3 && check(target, n, m, i)) {
            res.push_back(i);
        }
    }

    cout << res.size();
    for (int i = 0; i < res.size(); i++) {
        cout << " " << res[i];
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
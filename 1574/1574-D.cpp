#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> items(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int ci;
        cin >> ci;
        items[i].resize(ci);
        for (int j = 0; j < ci; j++) {
            cin >> items[i][j];
        }
    }

    int m;
    cin >> m;
    vector<vector<int>> banned(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> banned[i][j];
            banned[i][j]--;
        }
    }

    sort(banned.begin(), banned.end());

    vector<int> best(n);
    for (int i = 0; i < n; i++) {
        best[i] = items[i].size() - 1;
    }
    if (!binary_search(banned.begin(), banned.end(), best)) {
        for (int i = 0; i < n; i++) {
            cout << best[i] + 1 << " ";
        }
        cout << endl;
        return;
    }

    int global_maximal = 0;
    vector<int> res;
    for (int i = 0; i < m; i++) {
        vector<int> tmp = banned[i];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += items[j][tmp[j]];
        }

        for (int j = 0; j < n; j++) {
            if (tmp[j] > 0) {
                tmp[j]--;
                if (!binary_search(banned.begin(), banned.end(), tmp) && sum - items[j][tmp[j]+1] + items[j][tmp[j]] > global_maximal) {
                    res = tmp;
                    global_maximal = sum - items[j][tmp[j]+1] + items[j][tmp[j]];
                }
                tmp[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    solve();
}
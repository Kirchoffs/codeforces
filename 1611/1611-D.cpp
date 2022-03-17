#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> index_p(n);
    for (int i = 0; i < n; i++) {
        index_p[p[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (b[i] != i) {
            if (index_p[i] <= index_p[b[i]]) {
                cout << "-1" << endl;
                return;
            }
        }
    }

    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        dist[p[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] - dist[b[i]] << " ";
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
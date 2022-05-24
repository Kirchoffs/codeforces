#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> desktop(n * m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            desktop[j * n + i] = row[j] == '*';
            cnt += row[j] == '*' ? 1 : 0;
        }
    }

    int pre_cnt = 0;
    for (int i = 0; i < cnt; i++) {
        if (desktop[i]) {
            pre_cnt++;
        }
    }

    vector<int> res(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        int idx = (y - 1) * n + (x - 1);

        if (desktop[idx]) {
            if (desktop[cnt - 1]) {
                pre_cnt--;
            }
            if (idx < cnt && idx != cnt - 1) {
                pre_cnt--;
            }

            cnt--;
        } else {
            cnt++;

            if (desktop[cnt - 1] || idx == cnt - 1) {
                pre_cnt++;
            }
            if (idx < cnt && idx != cnt - 1) {
                pre_cnt++;
            }
        }

        desktop[idx] = !desktop[idx];
        res[i] = cnt - pre_cnt;
    }

    for (int i = 0; i < k; i++) {
        cout << res[i] << endl;
    }
}

int main() {
    solve();
}
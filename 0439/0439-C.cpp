#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

// e parts with even sum and k - e parts with odd sum
void solve() {
    int n, k, e, o;
    cin >> n >> k >> e;
    o = k - e;

    vector<queue<int>> a(2);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a[tmp % 2].push(tmp);
    }

    int e_a_cnt = a[0].size(), o_a_cnt = a[1].size();
    if (o > o_a_cnt || (o_a_cnt - o) % 2 != 0 || e > e_a_cnt + (o_a_cnt - o) / 2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    if (e == 0) {
        o--;
    }

    for (int i = 0; i < o; i++) {
        cout << 1 << " " << a[1].front() << endl;
        a[1].pop();
    }
    for (int i = 0; i < e - 1; i++) {
        if (a[0].size() > 0) {
            cout << 1 << " " << a[0].front() << endl;
            a[0].pop();
        } else {
            int first = a[1].front();
            a[1].pop();
            int second = a[1].front();
            a[1].pop();

            cout << 2 << " " << first << " " << second << endl;
        }
    }

    cout << a[0].size() + a[1].size() << " ";
    while (!a[0].empty()) {
        cout << a[0].front() << " ";
        a[0].pop();
    }
    while (!a[1].empty()) {
        cout << a[1].front() << " ";
        a[1].pop();
    }

    cout << endl;
}

int main() {
    solve();
}
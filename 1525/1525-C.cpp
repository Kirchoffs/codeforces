#include <iostream>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>
using namespace std;

static void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pos(n);

    for (int i = 0; i < n; i++) {
        cin >> pos[i].first;
    }

    for (int i = 0; i < n; i++) {
        char d;
        cin >> d;
        if (d == 'L') {
            pos[i].second = -1;
        } else {
            pos[i].second = 1;
        }
    }
    
    vector<int> ord(n, 0);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&pos](int a, int b) {
        return pos[a].first < pos[b].first;
    });

    vector<int> ans(n, -1);

    vector<stack<int>> stk(2);

    for (int index: ord) {
        int x = pos[index].first;
        int d = pos[index].second;
        int stk_id = x % 2;
        if (d == -1) {
            if (stk[stk_id].empty()) {
                stk[stk_id].push(index);
            } else {
                int prev_index = stk[stk_id].top();
                stk[stk_id].pop();
                ans[index] = ans[prev_index] = (x - pos[prev_index].second * pos[prev_index].first) / 2;
            }
        } else {
            stk[stk_id].push(index);
        }
    }

    for (auto& stk_queue: stk) {
        while (stk_queue.size() > 1) {
            int last = stk_queue.top();
            stk_queue.pop();
            int second_to_last = stk_queue.top();
            stk_queue.pop();

            ans[last] = ans[second_to_last] = (2 * m - pos[last].first - pos[second_to_last].second * pos[second_to_last].first) / 2;
        }
    }

    for (int an: ans) {
        cout << an << " ";
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
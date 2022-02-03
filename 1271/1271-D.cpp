#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class pair_compare {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> castles(n, vector<int>(3, 0));
    // number of warriors required, number of warriors can be hired, importance
    for (int i = 0; i < n; i++) {
        cin >> castles[i][0] >> castles[i][1] >> castles[i][2];
    }
    
    vector<int> next_helper(n);
    for (int i = 0; i < n; i++) {
        next_helper[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v; // u > v
        cin >> u >> v;
        u--;
        v--;
        next_helper[v] = max(next_helper[v], u);
    }
    map<int, vector<int>> portals;
    for (int i = 0; i < n; i++) {
        portals[next_helper[i]].push_back(i);
    }
    for (auto& prev_castles: portals) {
        sort(prev_castles.second.begin(), prev_castles.second.end(), [&](int a, int b) {
            return castles[a][1] > castles[b][1];
        });
    }

    // {id, val}
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_compare> pq;
    set<int> defended;
    int cur = k;
    int val = 0;
    for (int i = 0; i < n; i++) {
        while (cur < castles[i][0]) {
            if (pq.empty()) {
                cout << -1;
                return 0;
            }
            cur++;
            val -= pq.top().second;
            defended.erase(pq.top().first);
            pq.pop();
        }

        cur += castles[i][1];

        for (auto const& v: portals[i]) {
            if (defended.find(v) == defended.end()) {
                cur--;
                val += castles[v][2];
                defended.insert(v);
                pq.push({v, castles[v][2]});

                if (cur < 0) {
                    cur++;
                    val -= pq.top().second;
                    defended.erase(pq.top().first);
                    pq.pop();
                }
            }
        }
    }

    cout << val;
}
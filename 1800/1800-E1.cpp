#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

class UF {
private:
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    UF(int n): n(n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_op(int i) {
        if (parent[i] != i) {
            parent[i] = find_op(parent[i]);
        }
        return parent[i];
    }

    void union_op(int i, int j) {
        int ir = find_op(i);
        int jr = find_op(j);

        if (rank[ir] < rank[jr]) {
            parent[ir] = jr;
        } else if (rank[ir] > rank[jr]) {
            parent[jr] = ir;
        } else {
            parent[ir] = jr;
            rank[jr]++;
        }
    }

    unordered_map<int, vector<int>> groups_info() {
        unordered_map<int, vector<int>> groups;
        
        for (int i = 0; i < n; i++) {
            groups[find_op(i)].push_back(i);
        }

        return groups;
    }
};

void solve() {
    int n, k;
    cin >> n >> k; // k is always 3

    string s, t;
    cin >> s >> t;

    UF uf(n);
    for (int i = 0; i < n; i++) {
        if (i + 3 < n) {
            uf.union_op(i, i + 3);
        }
        if (i + 4 < n) {
            uf.union_op(i, i + 4);
        }
    }

    unordered_map<int, vector<int>> groups = uf.groups_info();
    for (auto& group: groups) {
        vector<int> group_cnt(26);
        for (int idx: group.second) {
            group_cnt[s[idx] - 'a']++;
            group_cnt[t[idx] - 'a']--;
        }
        for (int cnt: group_cnt) {
            if (cnt != 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
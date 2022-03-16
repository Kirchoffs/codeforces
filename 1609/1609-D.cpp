#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

class UF {
private:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    int extra = 0;

public:
    UF(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void union_op(int i, int j) {
        int ir = find_op(i);
        int jr = find_op(j);

        if (ir != jr) {
            if (rank[ir] < rank[jr]) {
                parent[ir] = jr;
                size[jr] += size[ir];
            } else if (rank[ir] > rank[jr]) {
                parent[jr] = ir;
                size[ir] += size[jr];
            } else {
                parent[ir] = jr;
                rank[jr]++;
                size[jr] += size[ir];
            }
        } else {
            extra++;
        }
    }

    int find_op(int i) {
        if (parent[i] != i) {
            parent[i] = find_op(parent[i]);
        }
        return parent[i];
    }

    bool is_connected(int i, int j) {
        return find_op(i) == find_op(j);
    }

    int get_most_acquaintances() {
        vector<bool> counted(parent.size(), false);
        vector<int> sorted_size;
        for (int i = 1; i < parent.size(); i++) {
            int root = find_op(i);
            if (!counted[root]) {
                counted[root] = true;
                sorted_size.push_back(size[root]);
            }
        }
        sort(sorted_size.begin(), sorted_size.end(), greater<int>());
        int sum = sorted_size[0];
        for (int i = 1; i <= extra; i++) {
            sum += sorted_size[i];
        }

        return sum - 1;
    }
};

void solve() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> conditions(d);
    for (int i = 0; i < d; i++) {
        cin >> conditions[i].first >> conditions[i].second;
    }

    UF uf(n);

    for (int i = 0; i < d; i++) {
        uf.union_op(conditions[i].first, conditions[i].second);
        cout << uf.get_most_acquaintances() << endl;
    }
}

int main() {
    solve();
}
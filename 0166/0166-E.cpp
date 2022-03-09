#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll mod = (int)(1e9 + 7);

vector<vector<ll>> matrix_mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    int r = a.size(), n = a[0].size();
    int c = b[0].size();

    vector<vector<ll>> res(r, vector<ll>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }

    return res;
}

vector<vector<ll>> quick_matrix_pow(vector<vector<ll>> base_matrix, int n) {
    int m = base_matrix.size();
    vector<vector<ll>> res(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++) {
        res[i][i] = 1;
    }

    while (n > 0) {
        if (n % 2 != 0) {
            res = matrix_mul(res, base_matrix);
        }
        base_matrix = matrix_mul(base_matrix, base_matrix);
        n /= 2;
    }
    
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<ll>> initial_state(4, vector<ll>(1, 0));
    initial_state[0][0] = 1;

    vector<vector<ll>> base_matrix(4, vector<ll>(4, 1));
    for (int i = 0; i < 4; i++) {
        base_matrix[i][i] = 0;
    }

    vector<vector<ll>> pow_matrix = quick_matrix_pow(base_matrix, n);
    vector<vector<ll>> final_state = matrix_mul(pow_matrix, initial_state);

    cout << final_state[0][0] << endl;
}

int main() {
    solve();
}
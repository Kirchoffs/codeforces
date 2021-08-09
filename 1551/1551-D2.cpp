#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_valid(int n, int m, int k) {
    if (n % 2 == 0 && m % 2 == 0) {
        return k % 2 == 0;
    } else if (n % 2 != 0 && m % 2 == 0) {
        return k >= m / 2 && (k - m / 2) % 2 == 0;
    } else {
        return is_valid(m, n, m * n / 2 - k);
    }
}

void draw_type_one(int n, int m, int k, vector<string>& graph, int start_row_index) {
    int letter = 0;
    int row_index = start_row_index;
    int col_index = 0;
    while (k > 0) {
        if (row_index >= n) {
            row_index = start_row_index;
            col_index += 2;
        }

        if (row_index > 0 && graph[row_index - 1][col_index] == (char)('a' + letter)) {
            letter = (letter + 1) % 26;
        }        
        if (col_index > 0 && graph[row_index][col_index - 1] == (char)('a' + letter)) {
            letter = (letter + 1) % 26;
        }

        graph[row_index][col_index] = (char)('a' + letter);
        graph[row_index][col_index + 1] = (char)('a' + letter);
        row_index++;
        letter = (letter + 1) % 26;
        k--;
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (graph[i][j] == '0') {
                if (i > 0) {
                    letter = (graph[i-1][j] - 'a' + 1) % 26;
                }
                if (j > 0) {
                    if (graph[i][j - 1] == (char)('a' + letter)) {
                        letter = (letter + 1) % 26;
                    }
                    if (graph[i+1][j-1] == (char)('a' + letter)) {
                        letter = (letter + 1) % 26;
                    }
                }

                graph[i][j] = (char)('a' + letter);
                graph[i+1][j] = (char)('a' + letter);
            }
        }
    }
}

void draw_type_two(int n, int m, int k, vector<string>& graph) {
    int letter = 0;
    for (int j = 0; j < m; j += 2) {
        graph[0][j] = (char)('a' + letter);
        graph[0][j+1] = (char)('a' + letter);
        letter = (letter + 1) % 26;
    }

    k -= m / 2;
    draw_type_one(n, m, k, graph, 1);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (is_valid(n, m, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        return;
    }

    vector<string> graph(n, string(m, '0'));
    if (n % 2 == 0 && m % 2 == 0) {
        draw_type_one(n, m, k, graph, 0);
    } else if (n % 2 == 1) {
        draw_type_two(n, m, k, graph);
    } else {
        vector<string> transpose_graph(m, string(n, '0'));
        draw_type_two(m, n, m * n / 2 - k, transpose_graph);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                graph[i][j] = transpose_graph[j][i];
            }
        }
    }

    for (string& row: graph) {
        cout << row << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static void solve() {
    int n;
    cin >> n;

    vector<vector<int>> cnts(26, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        for (int j = 0; j < word.length(); j++) {
            cnts[word[j] - 'a'][i]++;
        }
        for (int j = 0; j < 26; j++) {
            cnts[j][i] -= (word.length() - cnts[j][i]);
        }
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
        sort(cnts[i].begin(), cnts[i].end(), greater<int>());

        int value = 0;
        int j = 0;
        while (j < cnts[i].size()) {
            if (value + cnts[i][j] <= 0) {
                break;
            }
            value += cnts[i][j];
            j++;
        }
        res = max(res, j);
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
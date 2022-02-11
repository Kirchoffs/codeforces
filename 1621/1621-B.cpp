#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> segments(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        cin >> segments[i][0] >> segments[i][1] >> segments[i][2];
    }

    int min_index = 0;
    int max_index = 0;
    int longest_index = 0;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        if (segments[i][0] < segments[min_index][0]) {
            min_index = i;
        } else if (segments[i][0] == segments[min_index][0]) {
            if (segments[i][2] < segments[min_index][2]) {
                min_index = i;
            }
        }

        if (segments[i][1] > segments[max_index][1]) {
            max_index = i;
        } else if (segments[i][1] == segments[max_index][1]) {
            if (segments[i][2] < segments[max_index][2]) {
                max_index = i;
            }
        }

        if (segments[i][1] - segments[i][0] > segments[longest_index][1] - segments[longest_index][0]) {
            longest_index = i;
        } else if (segments[i][1] - segments[i][0] == segments[longest_index][1] - segments[longest_index][0]) {
            if (segments[i][2] < segments[longest_index][2]) {
                longest_index = i;
            }
        }

        if (segments[max_index][1] - segments[min_index][0] > segments[longest_index][1] - segments[longest_index][0]) {
            res[i] = segments[max_index][2] + segments[min_index][2];
        } else if (segments[max_index][1] - segments[min_index][0] < segments[longest_index][1] - segments[longest_index][0]) {
            res[i] = segments[longest_index][2];
        } else {
            res[i] = min(segments[max_index][2] + segments[min_index][2], segments[longest_index][2]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int best_candidate(vector<int>& arr, int base) {
    int best_idx = -1;
    int min_diff = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i] - base) < min_diff) {
            best_idx = i;
            min_diff = abs(arr[i] - base);
        }
    }

    return best_idx;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll res = INT_MAX;
    vector<int> first_choices = {0, best_candidate(b, a[0]), n - 1};
    vector<int> last_choices = {0, best_candidate(b, a[n-1]), n - 1};
    for (int first_choice: first_choices) {
        for (int last_choice: last_choices) {
            ll re = abs(a[0] - b[first_choice]) + abs(a[n-1] - b[last_choice]);

            if (first_choice > 0 && last_choice > 0) {
                re += abs(b[0] - a[best_candidate(a, b[0])]);
            }
            if (first_choice < n - 1 && last_choice < n - 1) {
                re += abs(b[n-1] - a[best_candidate(a, b[n-1])]);
            }

            if (re < res) {
                res = re;
            }
        }
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
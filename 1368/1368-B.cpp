#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    ll k;
    cin >> k;

    string s = "codeforces";
    vector<int> count_s(s.length(), 1);

    ll prod = 1;
    while (prod < k) {
        for (int i = 0; i < count_s.size(); i++) {
            count_s[i]++;
            prod /= (count_s[i] - 1);
            prod *= count_s[i];
            if (prod >= k) {
                break;
            }
        }
    }

    string res = "";
    for (int i = 0; i < count_s.size(); i++) {
        while (count_s[i] > 0) {
            res.push_back(s[i]);
            count_s[i]--;
        }
    }

    cout << res << endl;
}

int main() {
    solve();
}
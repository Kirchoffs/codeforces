#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for (int i = 0; i < s.length(); i++) {
        cnt[s[i] - 'a']++;
    }

    int odd_cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd_cnt++;
        }
    }

    if (odd_cnt <= 1) {
        cout << "First" << endl;
    } else {
        if (odd_cnt % 2 == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
}

int main() {
    solve();
}
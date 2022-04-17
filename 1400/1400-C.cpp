#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

string transform(vector<int>& original) {
    string res = "";
    for (int num: original) {
        if (num == -1) {
            num = 1;
        }
        res += to_string(num);
    }

    return res;
}

void solve() {
    string s;
    int x;
    cin >> s >> x;
    
    vector<int> original(s.length(), -1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            if (i + x < s.length()) {
                original[i + x] = 0;
            }
            if (i - x >= 0) {
                original[i - x] = 0;
            }
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            bool is_possible = false;
            if (i + x < s.length() && original[i + x] != 0) {
                is_possible = true;
                original[i + x] = 1;
            }
            if (i - x >= 0 && original[i - x] != 0) {
                is_possible = true;
                original[i - x] = 1;
            }

            if (!is_possible) {
                cout << "-1" << endl;
                return;
            }
        }
    }

    cout << transform(original) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
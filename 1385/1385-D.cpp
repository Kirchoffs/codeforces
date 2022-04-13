#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int calculate(string& s, int i, int j, char ch) {
    if (i == j) {
        if (s[i] == ch) {
            return 0;
        }
        return 1;
    }

    int m = i + (j - i) / 2;

    int first_half_ch = calculate(s, m + 1, j, ch + 1);
    first_half_ch += (j - i + 1) / 2 - count(s.begin() + i, s.begin() + m + 1, ch);

    int second_half_ch = calculate(s, i, m, ch + 1);
    second_half_ch += (j - i + 1) / 2 - count(s.begin() + m + 1, s.begin() + j + 1, ch);

    return min(first_half_ch, second_half_ch);
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    cout << calculate(s, 0, n - 1, 'a') << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
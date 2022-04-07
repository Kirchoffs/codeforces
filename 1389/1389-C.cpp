#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int helper(string& s, int a, int b) {
    int res = 0;
    for (char ch: s) {
        if (ch - '0' == a) {
            res++;
            swap(a, b);
        }
    }

    if (a != b && res % 2 == 1) {
        res--;
    }

    return res;
}

// t_2 t_3 t_4 t_5 ... t_(n-1) t_n     t_1
// t_n t_1 t_2 t_3 ... t_(n-3) t_(n-2) t_(n-1)

// t_1 = t_3 = t_5 = ... = t_(n-1)
// t_2 = t_4 = t_6 = ... = t_n
// if n == 2k
//   t_1 = t_3 = ... = t_(2k-1)
//   t_2 = t_4 = ... = t_2k
// else if n = 2k - 1
//   t_1 = t_2 = t_3 = ... = t_n

// In a word
// s should either be xxxxxx or xyxyxy
void solve() {
    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            res = max(res, helper(s, i, j));
        }
    }

    cout << s.length() - res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
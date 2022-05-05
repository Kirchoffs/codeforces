#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int helper(string s, int n, int k, char ch) {
    int l = 0, r = 0;
    int cnt = 0;
    int res = 0;
    while (r < n) {
        if (s[r] != ch) {
            cnt++;
        }

        while (cnt > k) {
            if (s[l] != ch) {
                cnt--;
            }
            l++;
        }

        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;

    cout << max(helper(s, n, k, 'a'), helper(s, n, k, 'b')) << endl;
}

int main() {
    solve();
}
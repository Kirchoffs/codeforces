#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void get_base(string s, int k, vector<ll>& base) {
    int i = 0;
    while (i < s.length()) {
        int j = i;
        while (j < s.length() && s[j] == '*') {
            j++;
        }
        if (j > i) {
            base.push_back((j - i) * k + 1);
        }
        i = j + 1;
    }
}

string multiply(char ch, ll number) {
    string res = "";
    for (int i = 0; i < number; i++) {
        res.push_back(ch);
    }
    return res;
}

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;

    vector<ll> base;
    get_base(s, k, base);

    vector<ll> cnt;
    x--;
    int i = base.size() - 1;
    while (x > 0) {
        cnt.push_back(x % base[i]);
        x /= base[i];
        i--;
    }

    string res = "";
    int p = s.length() - 1;
    int q = 0;
    while (p >= 0) {
        while (p >= 0 && s[p] == 'a') {
            res.push_back('a');
            p--;
        }
        if (p >= 0 && s[p] == '*') {
            while (p >= 0 && s[p] == '*') {
                p--;
            }
            if (q < cnt.size()) {
                res.append(multiply('b', cnt[q++]));
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
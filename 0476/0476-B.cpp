#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll nchoosek(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

ll power(ll base, ll exponent) {
    ll res = 1;
    while (exponent != 0) {
        if (exponent % 2 != 0) {
            res = res * base;
        }
        base = base * base;
        exponent /= 2;
    }
    return res;
}

void solve() {
    string dst;
    string src;
    cin >> dst >> src;

    int plus = 0, minus = 0;
    for (int i = 0; i < dst.length(); i++) {
        if (dst[i] == '+') {
            plus++;
        } else if (dst[i] == '-') {
            minus++;
        }
    }

    for (int i = 0; i < src.length(); i++) {
        if (src[i] == '+') {
            plus--;
        } else if (src[i] == '-') {
            minus--;
        }
    }

    cout.precision(20);

    if (plus < 0 || minus < 0) {
        cout << fixed << 0 << endl;
        return;
    }

    cout << fixed << nchoosek(plus + minus, plus) * 1.0 / power(2, plus + minus) << endl;
}

int main() {
    solve();
}
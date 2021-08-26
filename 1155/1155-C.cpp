#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

static ll get_gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return get_gcd(b, a % b);
}

static ll get_arr_gcd(vector<ll>& arr) {
    if (arr.size() == 1) {
        return arr[0];
    }

    ll res = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        res = get_gcd(res, arr[i]);
    }

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> diff;
    
    ll prev;
    ll start;
    cin >> prev;
    start = prev;
    for (int i = 1; i < n; i++) {
        ll cur;
        cin >> cur;
        diff.push_back(cur - prev);
        prev = cur;
    }

    ll gcd = get_arr_gcd(diff);

    for (int i = 0; i < m; i++) {
        ll cur;
        cin >> cur;
        if (gcd % cur == 0) {   
            cout << "YES" << endl;
            cout << start << " " << (i + 1);
            return 0;
        }
    }
    cout << "NO" << endl;
}
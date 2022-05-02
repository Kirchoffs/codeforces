#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

string min_string(string a, string b) {
    if (a.compare("-1") == 0) {
        return b;
    }
    
    if (b.compare("-1") == 0) {
        return a;
    }

    if (a.length() > b.length()) {
        return a;
    }
    
    return b;
}

string erase(string& str, int cnt, int remainder) {
    if (cnt == str.length()) {
        return "-1";
    }

    string res = "";

    for (int i = str.length() - 1; i >= 0; i--) {
        if ((str[i] - '0') % 3 == remainder && cnt > 0) {
            cnt--;
            continue;
        }

        res.push_back(str[i]);
    }

    if (cnt > 0) {
        return "-1";
    }

    while (res.back() == '0') {
        res.pop_back();
    }

    if (res.length() == 0) {
        res.push_back('0');
    }

    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string n;
    cin >> n;

    int digits_sum = 0;
    for (int i = 0; i < n.length(); i++) {
        digits_sum += (n[i] - '0');
    }

    if (digits_sum % 3 == 0) {
        cout << n << endl;
    } else if (digits_sum % 3 == 1) {
        cout << min_string(erase(n, 1, 1), erase(n, 2, 2)) << endl;
    } else {
        cout << min_string(erase(n, 1, 2), erase(n, 2, 1)) << endl;
    }
}

int main() {
    solve();
}
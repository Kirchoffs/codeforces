#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static void transform_number_to_letter(string& str) {
    int r = 0;
    int i = 1;
    while (i < str.length()) {
        if (str[i] == 'C') {
            break;
        } else {
            r = r * 10 + (str[i] - '0');
        }
        i++;
    }

    i++;
    int c = 0;
    while (i < str.length()) {
        c = c * 10 + (str[i] - '0');
        i++;
    }

    string c_hex = "";
    while (c > 0) {
        c_hex += ((c - 1) % 26 + 'A');
        c = (c - 1)/ 26;
    }

    reverse(c_hex.begin(), c_hex.end());
    cout << c_hex << to_string(r) << endl;
}

static void transform_letter_to_number(string& str) {
    int i = 0;
    int c = 0;
    while (i < str.length()) {
        if (str[i] >= '0' && str[i] <= '9') {
            break;
        }
        c = c * 26 + (str[i] - 'A' + 1);
        i++;
    }

    int r = 0;
    while (i < str.length()) {
        r = r * 10 + (str[i] - '0');
        i++;
    }

    string res = "R" + to_string(r) + "C" + to_string(c);
    cout << res << endl;
}

static bool is_number_format(string& str) {
    if (str[0] != 'R') {
        return false;
    }

    int i = 1;
    while (i < str.length()) {
        if (str[i] > '9' || str[i] < '0') {
            break;
        }
        i++;
    }

    return i > 1 && str[i] == 'C';
}

static void solve() {
    string str;
    cin >> str;

    if (is_number_format(str)) {
        transform_number_to_letter(str);
    } else {
        transform_letter_to_number(str);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}
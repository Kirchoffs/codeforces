#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
using ll = long long;

/**
 * Another better way according to turorial:
 * Consider case n1=0 separately and print the sting of n0+1 zeros or n2+1 ones correspondingly.
 * Now our string has at least one pair "10" or "01". Let's form the pattern "101010 ... 10" of length n1+1. 
 * So, all substrings with the sum 1 are satisfied.
 * Now let's insert n0 zeros before the first zero, in this way we satisfy the substrings with the sum 0. 
 * And then just insert n2 ones before the first one, in this way we satisfy the substrings with the sum 2.
 */

void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    deque<int> dq;
    int add_one = n1 > 0 ? 1 - n1 % 2 : 0;

    for (int i = 0; i < n1 + n1 % 2; i++) {
        if (i % 2 == 0) {
            dq.push_back(1);
        } else {
            dq.push_back(0);
        }
    }

    if (n1 == 0 && n0 != 0) {
        n0++;
    }
    for (int i = 0; i < n0; i++) {
        dq.push_back(0);
    }

    if (n1 == 0 && n2 != 0) {
        n2++;
    }
    for (int i = 0; i < n2; i++) {
        dq.push_front(1);
    }

    for (int i = 0; i < add_one; i++) {
        dq.push_back(1);
    }

    string res = "";
    while (!dq.empty()) {
        res.push_back((char)(dq.front() + '0'));
        dq.pop_front();
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
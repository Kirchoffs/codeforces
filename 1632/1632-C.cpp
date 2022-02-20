#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

// operation 1: a = a + 1
// operation 2: b = b + 1
// operation 3: a = a | b

// Operation 3 will only be executed once, because once it is executed, a >= b, then we can only execute operation 2

// Suppose a is increased to ta, and b is increated to tb
// then the result should be (ta - a) + (tb - b) + (ta | tb - tb) + 1
// which is ta + ta | tb + 1 - a - b
void solve() {
    int a, b;
    cin >> a >> b;
    int res = b - a;
    for (int ta = a; ta < b; ta++) {
        int tb = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int b_bit = (b >> bit) & 1;
            if (((ta >> bit) & 1) == 0) {
                tb = tb | (b_bit << bit);
            } else {
                tb = tb | (1 << bit);
                if (b_bit == 0) { 
                    break;
                }
            }
        }
        res = min(res, ta + (ta | tb) + 1 - a - b);
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
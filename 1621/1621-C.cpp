#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int ask(int i) {
    cout << "? " << i << endl;
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void solve() {
    int n;
    cin >> n;

    vector<int> result(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (result[i] == -1) {
            int first = ask(i);
            int next = ask(i);
            int pre = first;
            while (next != first) {
                result[pre] = next;
                pre = next;
                next = ask(i);
            }
            result[pre]= next;
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
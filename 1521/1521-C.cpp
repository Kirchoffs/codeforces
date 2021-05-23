#include <iostream>
#include <vector>
using namespace std;

int ask(int type, int i, int j, int x) {
    cout << "?" << " " << type << " " << i << " " << j << " " << x << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int max_pos = n;
    for (int i = 1; i <= n - 1; i += 2) {
        int ans = ask(1, i, i + 1, n - 1);
        if (ans == n) {
            max_pos = i + 1;
            break;
        } else if (ans == n - 1) {
            ans = ask(1, i + 1, i, n - 1);
            if (ans == n) {
                max_pos = i;
                break;
            }
        }
    }
    vector<int> nums(n + 1, 0);
    nums[max_pos] = n;
    for (int i = 1; i <= n; i++) {
        if (i != max_pos) {
            int res = ask(2, i, max_pos, 1);
            nums[i] = res;
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << nums[i] << " ";
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
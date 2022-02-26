#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll alice_candies = 0, alice_index = 0;
    ll bob_candies = 0, bob_index = n - 1;
    int steps = 0;
    ll last_candies = 0;
    bool is_alice = true;
    while (alice_index <= bob_index) {
        ll cur_candies = 0;
        if (is_alice) {
            while (alice_index <= bob_index && cur_candies <= last_candies) {
                cur_candies += a[alice_index];
                alice_index++;                
            }

            alice_candies += cur_candies;
        } else {
            while (alice_index <= bob_index && cur_candies <= last_candies) {
                cur_candies += a[bob_index];
                bob_index--;                
            }

            bob_candies += cur_candies;
        }
        is_alice = !is_alice;
        last_candies = cur_candies;
        steps++;
    }

    cout << steps << " " << alice_candies << " " << bob_candies << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
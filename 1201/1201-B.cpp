#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

// If the sum of the rest of the numbers is equal to the maximal number, 
// then we can always use the maximal as one of the pair.
// If it is greater than the maximal, we can randomly choose two elements among them and subtract 1,
// Untill the sum is equal to the maximal.
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll max_value = a[a.size() - 1];
    ll rest_sum = accumulate(a.begin(), a.end() - 1, 0LL);

    if (max_value > rest_sum || (max_value + rest_sum) % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    solve();
}
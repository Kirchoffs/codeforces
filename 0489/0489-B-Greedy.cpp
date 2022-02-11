#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
 
void solve() {
    int n;
    cin >> n;
    vector<int> boys(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> boys[i];
    }
 
    int m;
    cin >> m;
    vector<int> girls(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> girls[i];
    }
 
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int res = 0;
    int i = 0, j = 0;
    while (i < boys.size() && j < girls.size()) {
        if (abs(boys[i] - girls[j]) <= 1) {
            res++;
            i++;
            j++;
        } else if (boys[i] < girls[j]) {
            i++;
        } else {
            j++;
        }
    }
 
    cout << res << endl;
}
 
int main() {
    solve();
}
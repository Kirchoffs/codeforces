#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    vector<string> sudoko(9);
    for (int i = 0; i < 9; i++) {
        cin >> sudoko[i];
    }

    vector<int> indexes = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    vector<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 9; i++) {
        sudoko[i][indexes[i]] = numbers[(sudoko[i][indexes[i]] - '1' + 1) % 9];
    }

    for (int i = 0; i < 9; i++) {
        cout << sudoko[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
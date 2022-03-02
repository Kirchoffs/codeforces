#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    string n;
    cin >> n;
    int len = n.length();
    char last_digit = n[len - 1];
    int choice = -1;
    for (int i = 0; i < len - 1; i++) {
        if ((n[i] - '0') % 2 != 0) {
            continue;
        }
        choice = i;
        if (n[i] < last_digit) {   
            break;
        }
    }
    if (choice == -1) {
        cout << "-1" << endl;
        return;
    }
    swap(n[choice], n[len - 1]);
    cout << n << endl;
}

int main() {
    solve();
}
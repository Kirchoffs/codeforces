#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
using ll = long long;

bool is_palindrome(string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string reverse(string scene) {
    reverse(scene.begin(), scene.end());
    return scene;
}

void solve() {
    int n;
    cin >> n;
    vector<string> scenes(n);
    for (int i = 0; i < n; i++) {
        cin >> scenes[i];
    }
    unordered_set<string> visited;
    unordered_set<string> chopped_visited;
    for (int i = 0; i < n; i++) {
        string& scene = scenes[i];

        if (is_palindrome(scene)) {
            cout << "YES" << endl;
            return;
        }

        string reversed_scene = reverse(scene);
        if (visited.find(reversed_scene) != visited.end() || chopped_visited.find(reversed_scene) != chopped_visited.end()) {
            cout << "YES" << endl;
            return;
        }
        if (reversed_scene.length() == 3) {
            if (visited.find(reversed_scene.substr(0, 2)) != visited.end()) {
                cout << "YES" << endl;
                return;
            }
        }

        visited.insert(scene);
        if (scene.length() == 3) {
            chopped_visited.insert(scene.substr(0, 2));
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
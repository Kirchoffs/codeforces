#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, ll> scores;
    vector<pair<string, int>> process(n);
    for (int i = 0; i < n; i++) {
        string name;
        ll score;
        cin >> name >> score;
        process[i] = {name, score};
        scores[name] += score;
    }

    unordered_set<string> winners;
    ll winner_score = 0;
    for (auto& entry: scores) {
        if (entry.second > winner_score) {
            winner_score = entry.second;
            winners.clear();
            winners.insert(entry.first);
        } else if (entry.second == winner_score) {
            winners.insert(entry.first);
        }
    }

    string winner = "";
    scores.clear();
    for (auto& operation: process) {
        scores[operation.first] += operation.second;
        if (scores[operation.first] >= winner_score && winners.count(operation.first) > 0) {
            winner = operation.first;
            break;
        }
    }

    cout << winner << endl;
}

int main() {
    solve();
}
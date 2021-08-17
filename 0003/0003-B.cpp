#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    
    vector<pair<int, int>> kayaks;
    vector<pair<int, int>> catamarans;
    for (int i = 0; i < n; i++) {
        int type, capacity;
        cin >> type >> capacity;
        if (type == 1) {
            kayaks.push_back({i + 1, capacity});
        } else {
            catamarans.push_back({i + 1, capacity});
        }
    }

    sort(kayaks.begin(), kayaks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    sort(catamarans.begin(), catamarans.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    int res = 0;
    vector<int> candidates_katamarans;
    int i = 0;
    while (v >= 2 && i < catamarans.size()) {
        v -= 2;
        res += catamarans[i].second;
        candidates_katamarans.push_back(catamarans[i].first);
        i++;
    }

    vector<int> candidates_kayaks;
    int j = 0;
    while (v >= 1 && j < kayaks.size()) {
        v -= 1;
        res += kayaks[j].second;
        candidates_kayaks.push_back(kayaks[j].first);
        j++;
    }

    i--;
    while (j < kayaks.size() && i >= 0) {
        int contribute_kayaks = kayaks[j].second;
        if (j + 1 < kayaks.size()) {
            contribute_kayaks += kayaks[j + 1].second;
        }

        int contribute_katamarans = catamarans[i].second;

        if (contribute_kayaks >= contribute_katamarans) {
            res += (contribute_kayaks - contribute_katamarans);
            candidates_kayaks.push_back(kayaks[j].first);
            j++;
            if (j < kayaks.size()) {
                candidates_kayaks.push_back(kayaks[j].first);
                j++;
            }
            candidates_katamarans.pop_back();
            i--;
        } else {
            break;
        }
    }

    cout << res << endl;
    for (int candidate_kayaks: candidates_kayaks) {
        cout << candidate_kayaks << " ";
    }
    for (int candidate_katamaran: candidates_katamarans) {
        cout << candidate_katamaran << " ";
    }
    cout << endl;
}
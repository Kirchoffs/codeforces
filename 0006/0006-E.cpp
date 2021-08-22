#include <iostream>
#include <vector>
using namespace std;

static void build(vector<pair<int, int>>& st, int p, vector<int>& arr, int s, int e) {
    if (s == e) {
        st[p].first = arr[s];
        st[p].second = arr[s];
        return;
    }

    int m = s + (e - s) / 2;
    build(st, 2 * p + 1, arr, s, m);
    build(st, 2 * p + 2, arr, m + 1, e);

    st[p].first = min(st[2 * p + 1].first, st[2 * p + 2].first);
    st[p].second = max(st[2 * p + 1].second, st[2 * p + 2].second);
}

static pair<int, int> get_min_max(vector<pair<int, int>>& st, int p, int s, int e, int l, int r) {
    if (l <= s && r >= e) {
        return st[p];
    }
    int m = s + (e - s) / 2;
    int min_re = INT_MAX, max_re = INT_MIN;
    if (l <= m) {
        pair<int, int> left_query = get_min_max(st, 2 * p + 1, s, m, l, r);
        min_re = min(min_re, left_query.first);
        max_re = max(max_re, left_query.second);
    }

    if (r > m) {
        pair<int, int> right_query = get_min_max(st, 2 * p + 2, m + 1, e, l, r);
        min_re = min(min_re, right_query.first);
        max_re = max(max_re, right_query.second);
    }

    return make_pair(min_re, max_re);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> books(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    // {min, max}
    vector<pair<int, int>> st(n * 4);
    build(st, 0, books, 0, n - 1);

    int l = 0, r = 0;
    int max_length = 0;
    vector<pair<int, int>> res;
    while (r < n) {
        pair<int, int> cur = get_min_max(st, 0, 0, n - 1, l, r);
        while (l < r && cur.second - cur.first > k) {
            l++;
            cur = get_min_max(st, 0, 0, n - 1, l, r);
        }
        if (r - l + 1 > max_length) {
            max_length = r - l + 1;
            res.clear();
            res.emplace_back(l + 1, r + 1);
        } else if (r - l + 1 == max_length) {
            res.emplace_back(l + 1, r + 1);
        }
        r++;
    }

    cout << max_length << " " << res.size() << endl;
    for (pair<int, int>& re: res) {
        cout << re.first << " " << re.second << endl;
    }
    return 0;
}
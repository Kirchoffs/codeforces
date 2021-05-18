#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void check(vector<int>& nums, int x, vector<int>& res) {
    multiset<int> nums_set;
    for (int num: nums) {
        nums_set.insert(num);
    }
    while (!nums_set.empty()) {
        auto largest_ptr = nums_set.end();
        largest_ptr--;
        int remain = x - (*largest_ptr);
        nums_set.erase(largest_ptr);
        auto remain_ptr = nums_set.find(remain);
        if (remain_ptr == nums_set.end()) {
            return;
        }
        res.push_back(x - remain);
        res.push_back(remain);
        nums_set.erase(remain_ptr);
        x = x - remain;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n * 2, 0);
    for (int i = 0; i < n * 2; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n * 2 - 1; i++) {
        int x = nums[2 * n - 1] + nums[i];
        vector<int> res;
        check(nums, x, res);
        if (res.size() == n * 2) {
            cout << "YES" << endl;
            cout << x << endl;
            for (int i = 0; i < n * 2; i += 2) {
                cout << res[i] << " " << res[i+1] << endl;
            }
            return;
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
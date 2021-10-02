#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> next_courses(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        int ki;
        cin >> ki;
        indegree[i] += ki;
        for (int j = 0; j < ki; j++) {
            int course;
            cin >> course;
            next_courses[course].push_back(i);
        }
    }

    queue<int> courses;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            courses.push(i);
        }
    }

    int steps = 0;
    int count = 0;
    while (!courses.empty()) {
        int len = courses.size();
        map<int, int> ready;
        while (len > 0) {
            int cur = courses.front();
            courses.pop();
            count++;
            len--;

            for (int next_course: next_courses[cur]) {
                if (next_course > cur) {
                    indegree[next_course]--;
                    if (indegree[next_course] == 0) {
                        courses.push(next_course);
                        len++;
                    }
                } else {
                        ready[next_course]++;
                }
            }
        }

        for (auto const &entry: ready) {
            indegree[entry.first] -= entry.second;
            if (indegree[entry.first] == 0) {
                courses.push(entry.first);
            }
        }

        steps++;
    }

    if (count != n) {
        cout << -1 << endl;
    } else {
        cout << steps << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
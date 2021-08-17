#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int first = 0, second = 0;
    int rows[3];
    int cols[3];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    int diagonal = 0;
    int anti_diagonal = 0;
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 3; j++) {
            int value = str[j] == '.' ? 0 : (str[j] == 'X' ? 1 : -1);
            rows[i] += value;
            cols[j] += value;
            first += value == 1 ? 1 : 0;
            second += value == -1 ? 1 : 0;
            if (i == j) {
                diagonal += value;
            }
            if (i + j == 2) {
                anti_diagonal += value;
            }
        }
    }

    int wins_first = 0, wins_second =  0;
    for (int i = 0; i < 3; i++) {
        if (rows[i] == 3) {
            wins_first++;
        } else if (rows[i] == -3) {
            wins_second++;
        }

        if (cols[i] == 3) {
            wins_first++;
        } else if (cols[i] == -3) {
            wins_second++;
        }
    }
    wins_first += diagonal == 3 ? 1 : 0;
    wins_first += anti_diagonal == 3 ? 1 : 0;
    wins_second += diagonal == -3 ? 1 : 0;
    wins_second += anti_diagonal == -3 ? 1 : 0;

    if (!(first == second || first == second + 1)) {
        cout << "illegal" << endl;
        return 0;
    }
    if (first == second + 1 && wins_second > 0) {
        cout << "illegal" << endl;
        return 0;
    }
    if (first == second && wins_first > 0) {
        cout << "illegal" << endl;
        return 0;
    }
    if (wins_first > 0 && wins_second > 0) {
        cout << "illegal" << endl;
        return 0;
    }

    if (wins_first == 0 && wins_second == 0) {
        if (first == second) {
            cout << "first" << endl;
        } else if (first == second + 1) {
            if (first + second == 9) {
                cout << "draw" << endl;
            } else {
                cout << "second" << endl;
            }
        }
    } else if (wins_first > 0 && wins_second == 0) {
            cout << "the first player won" << endl;
    } else {
            cout << "the second player won" << endl;
    }
}
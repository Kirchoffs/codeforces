#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
using ll = long long;

static bool alloc_memory(vector<ll>& memory, int demand, ll id) {
    int i = 0;
    while (i < memory.size()) {
        if (memory[i] != 0) {
            i++;
        } else {
            int j = i;
            while (i < memory.size() && memory[i] == 0) {
                if (i - j + 1 == demand) {
                    for (int k = j; k <= i; k++) {
                        memory[k] = id;
                    }
                    return true;
                }
                i++;
            }
        }
    }
    return false;
}

static bool erase_memory(vector<ll>& memory, ll id) {
    bool ret = false;
    for (int i = 0; i < memory.size(); i++) {
        if (memory[i] == id) {
            memory[i] = 0;
            ret = true;
        }
    }
    return ret;
}

static void defragment_memory(vector<ll>& memory) {
    int i = 0, j = 0;
    while (j < memory.size()) {
        if (memory[j] != 0) {
            memory[i++] = memory[j];
        }
        j++;
    }

    while (i < memory.size()) {
        memory[i] = 0;
        i++;
    }
}

int main() {
    int t, m;
    cin >> t >> m;
    vector<ll> memory(m, 0);
    ll id = 1;
    for (int i = 0; i < t; i++) {
        string op;
        cin >> op;
        if (op.compare("alloc") == 0) {
            int demand;
            cin >> demand;

            if (alloc_memory(memory, demand, id)) {
                cout << id << endl;
                id++;
            } else {
                cout << "NULL" << endl;
            }

        } else if (op.compare("erase") == 0) {
            ll reclaim;
            cin >> reclaim;
            
            if (reclaim <= 0 || !erase_memory(memory, reclaim)) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else {
            defragment_memory(memory);
        }
    }
}
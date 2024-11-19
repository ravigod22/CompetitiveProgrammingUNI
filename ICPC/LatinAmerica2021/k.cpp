#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> s;
    vector<bool> exist(26, false);
    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        s.emplace_back(x);
        exist[x[0] - 'A'] = true;
    }

    for (auto e : s) {
        bool can = true;
        for (char c : e) {
            if (!exist[c - 'A']) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << "Y\n";
            return 0;
        }
    }
    cout << "N\n";
    return 0;
}

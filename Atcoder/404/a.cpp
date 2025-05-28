#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<bool> exist(26, false);
    for (auto e : s) {
        exist[e - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
        if (!exist[i]) {
            cout << char('a' + i) << "\n";
            return 0;
        }
    }
    return 0;
}

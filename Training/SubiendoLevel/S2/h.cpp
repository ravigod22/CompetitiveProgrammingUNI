#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> pos(26, 1);
    char last = '0';
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char op; cin >> op;
        string s; cin >> s;
        if (op == '!') {
            if (last != '0') ans += 1;
            for (int j = 0; j < 26; ++j) {
                if (!pos[j]) continue;
                bool nopos = false;
                for (auto e : s) {
                    if (e - 'a' == j) nopos = true;
                }
                if (!nopos) pos[j] = 0;
            }
        }
        else if (op == '.') {
            for (auto e : s) {
                pos[e - 'a'] = 0;
            }
        }
        else if (op == '?') {
            if (last == '0') {
                pos[s[0] - 'a'] = 0;
            }
            else {
                if (s[0] == last) break;
                else ans += 1;
            }
        }
        int cnt = count(pos.begin(), pos.end(), 1);
        if (cnt == 1) last = char('a' + find(pos.begin(), pos.end(), 1) - pos.begin());
    }
    cout << ans << "\n";
    return 0;
}

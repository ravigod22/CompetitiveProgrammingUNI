#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<pair<int, int>> res;
        stack<pair<char, int>> tmp;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '_') {
                if (tmp.empty()) {
                   s[i] = '(';
                   tmp.emplace('(', i);
                }
                else {
                    s[i] = ')';
                    auto e = tmp.top();
                    tmp.pop();
                    res.emplace_back(e.second, i);
                }
            }
            else {
                if (s[i] == ')') {
                    auto e = tmp.top();
                    tmp.pop();
                    res.emplace_back(e.second, i);
                }
                else {
                    tmp.emplace('(', i);
                }
            }
        }
        assert(tmp.empty());
        long long ans = 0;
        for (auto e : res) ans += 1LL * (e.second - e.first); 
        cout << ans << "\n";
    }
    return 0;
}


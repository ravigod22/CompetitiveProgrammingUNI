#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s; cin >> s;
    int pos[m + 2][k + 1];
    string ans;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int id = -1; 
        for (int j = 0; j < k; ++j) {
            char tmp = 'a' + j;
            int pos = m + 1;
            for (int l = p; l < m; ++l) {
                if (s[l] == tmp) {
                    pos = min(pos, l);
                }
            }
            id = max(id, pos);
        }
        assert(id != -1);
        if (id == m + 1) break;
        ans += s[id];
        p = id + 1;
    }
    bool can = (ans.size() < n ? false : true);
    while (ans.size() < n) {
        ans += 'a';
    }
    cout << (can ? "YES" : "NO") << "\n";
    if (!can) cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

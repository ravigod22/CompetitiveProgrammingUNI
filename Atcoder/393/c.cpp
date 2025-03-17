#include <bits/stdc++.h>
using namespace std;
const int n = 2e5 + 4;
vector<int> G[n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            mp[{u, v}]++;
        }
        int ans = 0;
        for (auto [edge, cnt] : mp) {
            auto [u, v] = edge;
            if (u == v) ans += cnt;
            else {
                ans += cnt - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}



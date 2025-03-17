#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> bits[30];
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 30; ++j) {
                if ((a[i] >> j) & 1) bits[j].push_back(i);
            }
        }
        for (int i = 0; i < 30; ++i) {
            sort(bits[i].begin(), bits[i].end(), [&] (int x, int y) {
                return a[x] > a[y];
            });
        }
        vector<int> ans;
        int prefixOr = 0;
        for (int i = 29; i >= 0; --i) {
            if ((prefixOr >> i) & 1) continue;
            int auxPrefix = prefixOr;
            int best = -1;
            for (int j = 0; j < (int)bits[i].size(); ++j) {
                if (vis[bits[i][j]]) continue;
                if (auxPrefix < (prefixOr | a[bits[i][j]])) {
                    auxPrefix = (prefixOr | a[bits[i][j]]);
                    best = bits[i][j];
                }
            }
            if (~best) {
                prefixOr = auxPrefix;
                vis[best] = true;
                ans.push_back(a[best]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            ans.push_back(a[i]);
        }
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}

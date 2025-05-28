#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (auto&[l, r] : p) cin >> l >> r;
    map<int, int> cnt;
    for (auto [l, r] : p) {
        cnt[l + r]++;
    }
    long long ans = 1LL * m * (m - 1) / 2;
    map<int, bool> vis;
    for (auto [k, v] : cnt) {
        if (vis[k] or vis[n + k]) continue;
        vis[k] = vis[n + k] = true;
        int total = v + cnt[n + k];
        ans -= 1LL * total * (total - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}


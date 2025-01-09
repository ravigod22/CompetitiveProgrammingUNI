#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    set<int> know;
    vector<int> a(m);
    for (int i = 1; i <= n; ++i) know.emplace(i);
    for (int& e : a) cin >> e;
    for (int i = 0; i < k; ++i) {
        int q; cin >> q;
        know.erase(q);
    }
    string ans(m, '0');
    if (know.size() > 1) {
        cout << ans << "\n";
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (know.count(a[i])) ans[i] = '1';
        if (know.empty()) ans[i] = '1';
    }
    cout << ans << "\n";
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



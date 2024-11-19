#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> tmp(n);
    for (auto& e : tmp) cin >> e;
    auto f = [&] (string a, string b) -> int {
        assert(a.size() == b.size());
        int k = a.size();
        int res = 0;
        for (int i = 0; i < k; ++i) {
            int t1 = a[i] - 'a';
            int t2 = b[i] - 'a';
            res += abs(t1 - t2);
        }
        return res;
    };
    int ans = 2e9;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = f(tmp[i], tmp[j]);
            ans = min(ans, cnt);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


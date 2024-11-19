#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> times(n);
    for (auto& e : times) cin >> e.first >> e.second;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (times[i].first - s >= 0) return true;
        }
        if (i == n - 1) {
            if (m - times[i].second >= s) return true;
        }
        if (i && i <= n - 1) {
            if (times[i].first - times[i - 1].second >= s) return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");        
    }
    return 0;
}


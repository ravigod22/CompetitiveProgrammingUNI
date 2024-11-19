#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    int grid[n][n];
    vector<int> cnt(2 * n + 1, 2e9);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            cnt[n - (i - j)] = min(cnt[n - (i - j)], grid[i][j]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (cnt[i] >= 0) continue;
        ans += abs(cnt[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



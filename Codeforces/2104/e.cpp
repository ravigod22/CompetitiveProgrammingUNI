#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int nxt[n + 1][k];
    for (int i = 0; i < k; ++i) nxt[n][i] = n + 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            nxt[i][j] = nxt[i + 1][j];       
        }
        nxt[i][s[i] - 'a'] = i + 1;
    }
    int dp[n + 2];
    dp[n + 1] = 0;
    for (int i = n; i >= 0; --i) {
        dp[i] = n;
        for (int j = 0; j < k; ++j) {
            dp[i] = min(dp[i], dp[nxt[i][j]]);
        }
        dp[i] += 1;
    }
    int m; cin >> m;
    while (m--) {
        string t; cin >> t;
        int p = 0;
        for (int i = 0; i < t.size() && p <= n; ++i) {
            p = nxt[p][t[i] - 'a'];
        }
        cout << dp[p] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




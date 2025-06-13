#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int mod = 1e9 + 7;
int n, m;

void solve() {
    cin >> n >> m;
    char grid[n][m];
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int j = 0; j < m; ++j) {
        set<char> mp;
        for (int i = 0; i < n; ++i) {
            mp.insert(grid[i][j]);
        }
        ans = (1LL * ans * mp.size()) % mod;
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





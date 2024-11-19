#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 1e3 + 5;
const long long inf = 1e18;
int n, m;
int x[maxn];
int c[maxn], y[maxn];
bool vis[maxn][maxn];
long long dp[maxn][maxn];

long long f(int pos, int remain) {
    if (pos == n) return (remain == n ? 0 : -inf);
    if (remain == n) return 0;
    if (vis[pos][remain]) return dp[pos][remain];
    vis[pos][remain] = true;
    long long& ans = dp[pos][remain] += f(0, remain + 1);
    ans = max(ans, 0LL + x[pos] + y[pos] + f(pos + 1, remain + 1));
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < m; ++i) {
        int pos, w; cin >> pos >> w;
        pos--;
        y[pos] = w;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, f(i, 0));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



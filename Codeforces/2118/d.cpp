#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int N = 5e2 + 10;
int n, k, q;
int d[N];
i64 p[N];
int vis[N][N][2];

bool dfs(int pos, int times, bool dir) {
    vis[pos][times][dir] = 1;
    int nxt = pos + (dir ? 1 : -1);
    i64 dis = abs(p[nxt] - p[pos]);
    dis %= k;
    int newtime = (times + dis) % k;
    bool newdir = (d[nxt] == newtime ? dir ^ 1 : dir);
    if (nxt < 0 || nxt >= n) return true;
    if (vis[nxt][newtime][newdir]) return false;
    else return dfs(nxt, newtime, newdir);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    cin >> q;
    while (q--) {
        i64 a;
        cin >> a;
        if (a > p[n - 1]) {
            cout << "YES\n";
            continue;
        }
        int pos = lower_bound(p, p + n, a) - p;
        int init = (p[pos] - a) % k;
        bool dir = (d[pos] == init ? 0 : 1);
        cout << (dfs(pos, init, dir) ? "YES" : "NO") << "\n";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < k; ++j)
                vis[i][j][0] = vis[i][j][1] = 0;
    }
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



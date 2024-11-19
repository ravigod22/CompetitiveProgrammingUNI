#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 2e5 + 5;
const int inf = 1e9;
int n, m;
vector<int> G[maxn];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        //G[v].emplace_back(u);
    }
    vector<int> dis(n, inf);
    dis[0] = 0;
    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[v] != inf) continue;
            dis[v] = dis[u] + 1;
            q.emplace(v);
        }
    }
    int ans = 2e5 + 5;
    for (int i = 1; i < n; ++i) {
        bool exist = false;
        for (int v : G[i]) {
            if (v == 0) exist = true;
        }
        if (exist) ans = min(ans, dis[i] + 1);
    }
    if (ans == 2e5 + 5) ans = -1;
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





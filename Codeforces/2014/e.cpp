#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using plli = pair<ll, int>;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


const int maxn = 4e5 + 5;
const ll inf = 1e18;
int n, m, h;

vector<pair<int, int>> G[maxn];

vector<ll> dijkstra(int s) {
    vector<ll> dis(2 * n, inf);
    dis[s] = 0;
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    pq.emplace(dis[s], s);
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u]) continue;
        for (auto [v, len] : G[u]) {
            if (dis[u] + 1LL * len < dis[v]) {
                dis[v] = dis[u] + len;
                pq.emplace(dis[v], v);
            }       
        }
    }
    return dis;
}

void solve() {
    cin >> n >> m >> h;
    fill(G, G + 2 * n, vector<pair<int, int>> ());
    // bridge
    for (int i = 0; i < h; ++i) {
        int x; cin >> x;
        x--;
        G[x].emplace_back(x + n, 0);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        G[u + n].emplace_back(v + n, w / 2);
        G[v + n].emplace_back(u + n, w / 2);
    }
    vector<ll> Robin = dijkstra(n - 1);
    vector<ll> Marian = dijkstra(0);
    long long ans = inf;
    for (int i = 0; i < n; ++i) {
        ll aux1 = min(Robin[i], Robin[i + n]);
        ll aux2 = min(Marian[i], Marian[i + n]);
        if (aux1 == inf || aux2 == inf) continue;
        ans = min(ans, max(aux1, aux2));
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}



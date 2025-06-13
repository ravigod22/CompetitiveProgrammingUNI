#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n,m;
int dp[N];
int par[N];
vector<int> v[N];
vector<pair<int,int>> T[N];

bool join(int a, int b) {
    a = par[a]; b = par[b];
    if (a == b) return 0;
    if (v[a].size() < v[b].size()) swap(a, b);
    for (int x : v[b]) {
        v[a].push_back(x);
        par[x] = a;
    }
    v[b].clear();
    return 1;
}

void dfs(int u, int p, int mx = 0) {
    dp[u] = mx;
    for (auto [v, w] : T[u]) {
        if (v == p) continue;
        dfs(v, u, max(mx, w));
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    
    for (int i = 0; i < N; i++) {
        par[i] = i;
        v[i] = {i};
    }

    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    
    for (auto [w, a, b] : edges) {
        if (join(a, b)) {
            T[a].emplace_back(b, w);
            T[b].emplace_back(a, w);
        }
    }

    dfs(0, 0);

    int d; cin >> d;
    vector<int> to(d);
    for (int i = 0; i < d; i++) {
        int x; cin >> x;
        x--;
        to[i] = dp[x];
    }
    sort(to.begin(), to.end());
    vector<int> L(d);
    for (int i = 0; i < d; i++) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());

    int j = 0;
    int cnt = 0;
    for (int x : to) {
        while(j < d and L[j] < x) {
            j++;
        } 
        if (j == d) break;
        cnt++;
        j++;
    }
    cout << cnt << "\n";

    return 0;
}

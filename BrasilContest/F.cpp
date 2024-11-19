#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int INF = 1e9;
const int mx = 1e3+5;
vector<int> g[mx];
vector<bool> vis(mx);
int ce = 0;
set<int> cv;

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    cv.insert(u);
    for (auto x : g[u]) {
        ce++;
        dfs(x);
    }
}

void solve() {
    int n, m, u, v; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cv.clear();
        ce = 0;
        dfs(i);
        if(cv.size() == ce/2 + 1) ans++;
    }
    cout << ans << endl;

}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}


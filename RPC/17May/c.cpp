#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,m;
int mx,node;
int c[N];
bool vis[N];
vector<int> G[N];
vector<string> ss;
map<string, int> id;

void dfs(int u) {
    vis[u] = true;
    
    if (c[u] > mx) {
        mx = c[u];
        node = u;
    } else if (c[u] == mx and u < node) {
        node = u;
    }

    for (int v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

void clean() {
    ss.clear();
    id.clear();
    for (int i = 0; i < n; i++) {
        G[i].clear();
        vis[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s >> c[i];
        ss.push_back(s);
        id[s] = i;
    }
    for (int i = 0; i < m; i++) {
        string a,b;
        cin >> a >> b;
        int u = id[a], v = id[b];
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        mx = node = -1;
        dfs(i);
        ans.push_back(node);
    }

    for (int i : ans) cout << ss[i] << "\n";

    clean();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4 + 5;
string s; 
vector<int> G[maxn];
pair<int, int> ans[maxn];
bool vis[maxn];

void DFS(int u) {
    vis[u] = true;
    ans[u].first += (s[u] == 'B' ? 1 : 0);
    ans[u].second += (s[u] == 'W' ? 1 : 0);
    for (int v : G[u]) {
        if (vis[v]) continue;
        DFS(v);
        ans[u].first += ans[v].first;
        ans[u].second += ans[v].second;
    }
}

void solve() {
    int n; cin >> n;
    fill(ans, ans + n, pair<int, int>());
    fill(G, G + n, vector<int>());
    fill(vis, vis + n, false);
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        p--;
        G[i].emplace_back(p);
        G[p].emplace_back(i);
    }
    cin >> s;
    DFS(0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i].first == ans[i].second) cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



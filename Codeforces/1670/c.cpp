#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
bool vis[N];
bool mark[N];
bool can;
vector<int> G[N];
vector<int> compo;

void dfs(int u) {
    vis[u] = true;
    compo.push_back(u);
    can |= mark[u];
    for (int v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            if (c[i]) {
                mark[a[i]] = mark[b[i]] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            G[a[i]].push_back(b[i]);
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            can = false;
            dfs(i);
            if (compo.size() > 1 && !can) {
                ans = (ans * 2) % mod;
            }
            compo.clear();
        }
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            G[i].clear();
            mark[i] = false;
            vis[i] = false;
        }
    }
    return 0;
}

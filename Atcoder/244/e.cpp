#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10;
const int mod = 998244353;
int n, m, k, s, t, x;
vector<int> G[maxn];

void solve() {
    cin >> n >> m >> k >> s >> t >> x;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
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


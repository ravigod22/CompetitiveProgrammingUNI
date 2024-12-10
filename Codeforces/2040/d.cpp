#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int value[maxn];
vector<int> G[maxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        G[i] = tmp;
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


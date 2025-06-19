#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int LOG = 20;
int n, q;
int up[N][LOG], h[N];
vector<int> G[N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        h[v] = 1 + h[u];
        dfs(v, u);
    }
}

int boss(int e, int dis) {
    if (dis > h[e]) return -1;
    for (int i = LOG - 1; i >= 0; --i) {
        if ((dis >> i) & 1) {
            e = up[e][i];
        }
    }
    return e + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }
    dfs(0, 0);
    while (q--) {
        int e, d;
        cin >> e >> d;
        e--;
        cout << boss(e, d) << "\n";
    }
    return 0;
}

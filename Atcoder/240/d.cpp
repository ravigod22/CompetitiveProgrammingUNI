#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int L[maxn];
int R[maxn];
int tim;
vector<int> G[maxn];

void dfs(int u, int p = -1) {
    if (G[u].size() == 1 && u != 0) {
        L[u] = R[u] = tim++;
    }
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        L[u] = min(L[u], L[v]);
        R[u] = max(R[u], R[v]);
    }
} 

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    tim = 1;
    fill(L, L + n, n);
    fill(R, R + n, 0);
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << L[i] << " " << R[i] << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 2e3 + 5;
int c[maxn], a[maxn];
vector<int> G[maxn];
vector<int> T[maxn];

i64 dfs(int u, int p = -1) {
    i64 res = 0;
    for (int v : T[u]) {
        if (v == p) continue;
        res += dfs(v, u);
    }
    for (int v : T[u]) {
        if (v == p) continue;
        if (a[v] > 0) res += 1;
        a[u] += a[v];
    }
    return res;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i - c[i]; j < i; ++j) {
            G[j].push_back(i);
        }
    }
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            q.push(v);
            T[u].push_back(v);
            T[v].push_back(u);
        }
    }
    i64 ans = dfs(0);
    cout << ans << "\n";
    return 0;
}
